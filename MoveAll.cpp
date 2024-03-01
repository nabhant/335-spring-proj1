#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

   for (auto it = source.begin(); it != source.end();) 
   {
    bool found = false; // Use this to track if the keyword is found
      for (const auto& kw : it->getKeywords()) 
      {
        if (kw == keyword) 
        {
          found = true;
          break; // Exit the loop early if the keyword is found
        }

      }

      if (found) 
      {
        dest.push_back(std::move(*it)); // Move the book to dest
        it = source.erase(it); // Erase returns the next iterator, so no need to increment
        books_moved++;
      } 
      
      else 
      {
        ++it; // Only increment if we didn't erase (move) the book
      }
    }


  // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}