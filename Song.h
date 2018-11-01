//
// Created by Matt Golla and Iva Sadler on 10/17/2018.
//
#ifndef SONG_H
#define SONG_H

#include <string>


using namespace std;

//Song class declaration
class Song{
    private:
        string title;
        string artist;
        int size;

    public:
    //Default constructor
    //sets all fields to blank
        Song();

    //Constructor with artist, size, title parameters
    //The user of the class will pass in a size, title, artist
    //assigns all three to the song object
        Song(string title, string artist, int size);

    /* FUNCTION - string getTitle()
     * gets the title name of the Song object
         o returns the title name


     precondition: s is a valid Song with a valid title

     input params - none

     output params - return a string which is the title
    */
        string getTitle() const;

    /* FUNCTION - string getArtist()
     * gets the artist name of the Song object
         o returns the artist name


     precondition: s is a valid Song with a valid artist

     input params - none

     output params - return a string which is the artist
    */
        string getArtist() const;

    /* FUNCTION - int getSize()
     * gets the size of the Song object
         o returns the size of the song


     precondition: s is a valid Song with a valid size

     input params - none

     output params - return a int which is the song size
    */
        int getSize() const;

    /* FUNCTION - void setTitle()
     * sets the title name of the Song object


     precondition: s is a valid Song

     input params - a string which is the title

     output params - none
    */
        void setTitle(string t);

    /* FUNCTION - void setArtist()
     * sets the artist name of the Song object


     precondition: s is a valid Song

     input params - a string which is the artist

     output params - none
    */
        void setArtist(string a);

    /* FUNCTION - void setSize()
     * sets the size of the Song object


     precondition: s is a valid Song

     input params - an int which is the song size

     output params - none
    */
        void setSize(int s);

    /* OPERATOR - bool operator <
     * compares two songs based on artists by alphabet, then title by alphabet, then size by number
          o returns true if the rhs is bigger
          o returns false if the rhs is smaller or equal
     precondition: both songs are  valid Songs

     input params - two Songs

     output params - boolean indicating the result of the comparison
    */
        bool operator < (const Song &rhs);

    /* OPERATOR - bool operator >
     * compares two songs based on artists by alphabet, then title by alphabet, then size by number
          o returns true if the rhs is smaller
          o returns false if the rhs is bigger or equal
     precondition: both songs are  valid Songs

     input params - two Songs

     output params - boolean indicating the result of the comparison
    */
        bool operator > (const Song &rhs);

    /* OPERATOR - bool operator =
     * compares two songs based on artists by alphabet, then title by alphabet, then size by number
          o returns true if the rhs is equal to the lhs
          o returns false if the rhs is smaller or bigger
     precondition: both songs are  valid Songs

     input params - two Songs

     output params - boolean indicating the result of the comparison
    */
        bool operator == (const Song &rhs);
};


#endif