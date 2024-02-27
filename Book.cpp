#include "Book.hpp"

    // write and document all methods in this file.

    /* Constructor */
    Book::Book()
    {

    }

    /* Destructor */
    Book::~Book()
    {
        delete[] icon_;
        icon_ = nullptr;
    }

    /* Copy Constructor */

    Book::Book(const Book& rhs){
        this->title_ = rhs.title_;
        this->author_ = rhs.author_;
        this->ISBN_ = rhs.ISBN_;
        this->price_ = rhs.price_;
        this->keywords_ = rhs.keywords_;
        this->blurb_= rhs.blurb_;
        std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
    }
    

    /* Copy Assignment Operator */

    Book& Book::operator=(const Book& rhs)
    {
        if (this == &rhs ){
            return *this;
        }
        if (icon_ != nullptr){
            delete[] icon_;
            icon_ = nullptr;
        }
        this->title_ = rhs.title_;
        this->author_ = rhs.author_;
        this->ISBN_ = rhs.ISBN_;
        this->price_ = rhs.price_;
        this->keywords_ = rhs.keywords_;
        this->blurb_= rhs.blurb_;
        std::copy(rhs.icon_, rhs.icon_ + 80, icon_);

        return *this;
    }

    /* Move Constructor */

    Book::Book(Book&& rhs)
    {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = std::move(rhs.ISBN_);
        price_ = std::move(rhs.price_);
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
    }

    /* Move Assignment Operator */


    // MUTATORS AND ACCESSORS 

    Book& Book::operator=(Book&& rhs)
    {

    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        icon_ = icon;
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }


    /* Print function */

    void Book::print() const
    {

    }