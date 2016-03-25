#ifndef CSIT_CLASS_H
#define CSIT_CLASS_H
class csit_class {
	private: int m_courseNumber;
	private: int m_sectionNumber;
	public: enum class members {
		CourseNumber,
		SectionNumber,
	};
	public: csit_class (const int&, const int&);
	public: int courseNumber () const;
	public: int sectionNumber () const;
	public: bool operator< (const csit_class&) const;
};
#endif