//
// Created by Iva Sadler and Matthew Golla on 10/28/2018.
//

#include "Song.h"
#include <iostream>

using namespace std;

Song::Song(){
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string artist, string title, int size) {
    this->title = title;
    this->artist = artist;
    this->size = size;
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}

void Song::setArtist(string a) {
    artist = a;
}

void Song::setSize(int s) {
    size = s;
}

void Song::setTitle(string t) {
    title = t;
}

bool Song::operator<(const Song &rhs) {
    if(artist<rhs.artist){
        return true;
    }
    else if(artist == rhs.artist){
        if(title<rhs.title){
            return true;
        }
        else if(title == rhs.title){
            if(size<rhs.size){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Song::operator>(const Song &rhs) {
    if(artist>rhs.artist){
        return true;
    }
    else if(artist == rhs.artist){
        if(title>rhs.title){
            return true;
        }
        else if(title == rhs.title){
            if(size>rhs.size){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Song::operator==(const Song &rhs) {
    return ((title == rhs.title) && (artist == rhs.artist) && (size==rhs.size));
}
