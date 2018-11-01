//
// Created by Iva Sadler and Matthew Golla on 10/28/2018.
//
#include <iostream>
#include "UtPod.h"
#include <time.h>
#include <stdlib.h>

using namespace std;


UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
    srand((unsigned) time(0));
}


UtPod::UtPod(int space) {
    if(space > 512 || space < 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = space;
    }
    songs = NULL;
    srand((unsigned) time(0));
}


int UtPod::addSong(Song const &s) {
    //check if song will fit in UtPod
    if(getRemainingMemory() >= s.getSize()) {
        SongNode *node;
        node = new SongNode;       //create new song node
        //if playlist empty, set it first
        if(songs == NULL){
            songs = node;
            node->s = s;
            node->next = NULL;

        }
        else {
            SongNode* temp = songs;
            while (temp->next != NULL) {
                temp = temp->next;             //iterate to the last song
            }
            temp->next = node;                 //last song now points to added song
            node->s = s;
            node->next = NULL;                 //added song now points to null
        }
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {
    //check if UtPod is empty
    if (songs == NULL) {
        return NOT_FOUND;
    }
    SongNode *temp = songs;
    SongNode *prev = songs;
    while (temp != NULL) {
        if (temp->s == s) {           //iterate through playlist, checking if same song
            if(temp == songs){
                songs = temp->next;
            }
            prev->next = temp->next;
            delete temp;
            return SUCCESS;         //if found, previous node now points to next node, delete song
        }
        prev = temp;
        temp = temp->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle() {
    int count = 0;
    SongNode *temp = songs;
    //find number of songs
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    //if 0 or 1 songs, no need to shuffle
    if(count >= 2) {
        //swap pair the number of songs times
        for(int i = 0; i < count; i++){
            //get two random indices 0 to number of songs - 1
            int index1 = rand() % count;
            int index2 = rand() % count;
            SongNode *p1 = songs;
            SongNode *p2 = songs;
            //iterate both pointers
            for (int j = 0; j < index1; j++) {
                p1 = p1->next;
            }
            for (int j = 0; j < index2; j++) {
                p2 = p2->next;
            }
            //swap songs
            Song stemp = p1->s;
            p1->s = p2->s;
            p2->s = stemp;
        }
    }
}


void UtPod::showSongList() {
    SongNode *temp = songs;
    //check if empty
    if(temp == NULL){
        cout << "No songs found!" << endl;
    }
    else {
        //iterate through list, printing out title, artist, and size for each song
        while (temp != NULL) {
            cout << (temp->s).getTitle() << ", " << temp->s.getArtist()
                 << ", " << temp->s.getSize() << endl;
            temp = temp->next;
        }
    }
}

void UtPod::sortSongList() {
    SongNode* minimum = songs;
    SongNode* start = songs;
    SongNode* temp = NULL;
    //nested iteration through list, inserting minimum song at front each time
    while(start != NULL){
        temp = start->next;
        while(temp != NULL){
            if(temp->s < minimum->s){
                minimum = temp;
            }
            temp = temp->next;
        }
        //swap each position with the remaining minimal song
        Song stemp = start->s;
        start->s = minimum->s;
        minimum->s = stemp;
        //reset pointers for next iteration
        start = start->next;
        minimum = start;
    }
}

void UtPod::clearMemory() {
    SongNode *temp = songs;
    SongNode *prev = NULL;
    //iterate through list, deleting each song
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    songs = NULL;
}


int UtPod::getRemainingMemory() {
    SongNode *temp = songs;
    int sum = 0;
    //iterate through list, summing up the size of each song
    while(temp != NULL){
        sum += temp->s.getSize();
        temp = temp->next;
    }
    //remaining memory = starting memory - currently used memory
    return getTotalMemory() - sum;
}

UtPod::~UtPod(){
    clearMemory();
}
