/* This program is built from code from Accelerated C++
 * Chapter 15. This program builds pictures in different ways
 * and helps to show inheritance.
 */

#ifndef CONCATPICTURES_H_
#define CONCATPICTURES_H_

#include "Ptr.h"
#include <iostream>
#include <vector>

// Need to declare now or the friend declarations for functions that
// return type Picture wont work. Compiler wont know Picture is a type.
class Picture;

// Base class that derives String, frame, VCat and HCat classes.
class Pic_Base {
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	typedef std::vector<std::string>::size_type ht_size;
	typedef std::string::size_type wd_size;

	virtual wd_size width() const = 0;
	virtual ht_size height() const = 0;
	virtual void display(std::ostream&, ht_size, bool) const = 0;

protected:
	static void pad(std::ostream& os, wd_size beg, wd_size end) {

		while (beg != end) {
			os << " ";
			++beg;
		}
	}
};

// Interface class to hide implementation.
class Picture {
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);

public:

	// If vector isn't supplied, it will make empty vector<string>.
	Picture(const std::vector<std::string>& =
			std::vector<std::string>());
	Picture(Pic_Base* ptr): p(ptr) { }

private:
	Ptr<Pic_Base> p;

};

class String_Pic: public Pic_Base {
	friend class Picture;

	std::vector<std::string> data;
	String_Pic(const std::vector<std::string>& v): data(v) { }

	wd_size width() const;
	ht_size height() const { return data.size(); }
	void display(std::ostream&, ht_size, bool) const;
};

class Frame_Pic: public Pic_Base {
	friend Picture frame(const Picture&);


	Ptr<Pic_Base> p;
	Frame_Pic(const Ptr<Pic_Base>& pic): p(pic) { }

	wd_size width() const { return p->width() + 4; }
	ht_size height() const { return p->height() + 4; }
	void display(std::ostream&, ht_size, bool) const;
};

class VCat_Pic: public Pic_Base {
	friend Picture vcat(const Picture&, const Picture&);

	Ptr<Pic_Base> top, bottom;
	VCat_Pic(const Ptr<Pic_Base>& t, const Ptr<Pic_Base>& b):
		top(t), bottom(b) { }

	wd_size width() const
		{ return std::max(top->width(), bottom->width()); }
	ht_size height() const
		{ return top->height() + bottom->height(); }
	void display(std::ostream&, ht_size, bool) const;
};


class HCat_Pic: public Pic_Base {
	friend Picture hcat(const Picture&, const Picture&);

	Ptr<Pic_Base> left, right;
	HCat_Pic(const Ptr<Pic_Base>& l, const Ptr<Pic_Base>& r):
		left(l), right(r) { }

	wd_size width() const { return left->width() + right->width(); }
	ht_size height() const
		{ return std::max(left->height(), right->height()); }
	void display(std::ostream&, ht_size, bool) const;
};





// Defining constructor for Picture(vector).
Picture::Picture(const std::vector<std::string>& v):
		p(new String_Pic(v)) { }




// Members of String_Pic.
Pic_Base::wd_size String_Pic::width() const {

	Pic_Base::wd_size n = 0;
	for (Pic_Base::ht_size i = 0; i != data.size(); ++i) {
		n = std::max(n, data[i].size());
	}

	return n;
}


void String_Pic::display(std::ostream& os, ht_size row, bool do_pad) const {

	wd_size start = 0;

	if (row < height()) {
		os << data[row];
		start = data[row].size();
	}

	if (do_pad) {
		pad(os, start, width());
	}
}



// Members of VCat_Pic.
void VCat_Pic::display(std::ostream& os, ht_size row, bool do_pad) const {

	wd_size w = 0;

	// In top half of picture.
	if (row < top->height()) {
		top->display(os, row, do_pad);
		w = top->width();
	}

	// In bottom half of picture.
	else if (row < height()) {
		bottom->display(os, row - top->height(), do_pad);
		w = bottom->width();
	}

	if (do_pad) {
		pad(os, w, width());
	}
}


// Members of HCat_Pic.
void HCat_Pic::display(std::ostream& os, ht_size row, bool do_pad) const {

	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}


// Members of Frame_Pic.
void Frame_Pic::display(std::ostream& os, ht_size row, bool do_pad) const {

	if (row >= height()) {
		// Out of range.
		if (do_pad) {
			pad(os, 0, width());
		}
	}
	else {
		if (row == 0 || row == height() - 1) {
			// Top or bottom row.
			os << std::string(width(), '*');
		}
		else if (row == 1 || row == height() - 2) {
			// Second from top or bottom.
			os << "*";
			pad(os, 1, width() - 1);
			os << "*";
		}
		else {
			os << "* ";
			p->display(os, row - 2, true);
			os << " *";
		}
	}
}


// Utility members.
Picture frame(const Picture& pic) {

	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r) {

	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b) {

	return new VCat_Pic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture) {

	const Pic_Base::ht_size ht = picture.p->height();
	for (Pic_Base::ht_size i = 0; i != ht; ++i) {
		picture.p->display(os, i, false);
		os << std::endl;
	}

	return os;
}



#endif
