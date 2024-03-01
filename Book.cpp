#include "Book.hpp"

    // write and document all methods in this file.

    /* Constructor */
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr;
        price_ = 0.0;
        keywords_ = {};
        blurb_ = "";
    }

    /* Destructor */
    Book::~Book()
    {
        delete[] icon_;
        icon_ = nullptr;
    }

    /* Copy Constructor */

    Book::Book(const Book& rhs){
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_= rhs.blurb_;
        icon_ = new int[80];
        for (int i = 0; i < 80; ++i)
        {
        icon_[i] = rhs.icon_[i]; 
        }
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
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_= rhs.blurb_;
        icon_ = new int[80];
        for (int i = 0; i < 80; ++i)
        {
        icon_[i] = rhs.icon_[i]; 
        }

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


    Book& Book::operator=(Book&& rhs)
    {
        if (this != &rhs)
        {
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = std::move(rhs.ISBN_);
            price_ = std::move(rhs.price_);
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
            delete[] icon_;               
            icon_ = std::move(rhs.icon_);  
            rhs.icon_ = nullptr; 
        }
        return *this;
    }

 // MUTATORS AND ACCESSORS 
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
        std::cout<<"Title: " << title_<<std::endl;
        std::cout<<"Author: " << author_<<std::endl;
        std::cout<<"ISBN: " << ISBN_<<std::endl;
        std::cout<<"Icon: ";
        if (icon_ != NULL)
        {
            for (int i = 0; i < 80; i++)
            {
                std::cout<<icon_[i]<< " ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::fixed<<std::setprecision(2)<<"Price: $" << price_<<std::endl;

        for (auto it = keywords_.begin(); it!=keywords_.end(); ++it){
            std::cout<<*it;
            if (std::next(it)!= keywords_.end() - 1 )
                std::cout<<", ";
        }
        std::cout<<std::endl;
        std::cout<<"Blurb: " << blurb_<<std::endl;

    }