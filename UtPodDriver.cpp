/* utPod_driver.cpp
Demo Driver for the UtPod.

Iva Sadler and Matthew Golla
EE 312 10/16/18

Driver for the UtPod.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    //general test case of all functions
    cout << "General test case of all functions and operators" << endl;
    UtPod rock(-1); //test of negative input for UtPod
    Song a("Mom Jeans.", "Death Cup", 14);
    Song b("Oso Oso", "This Must Be My Exit", 20);
    Song c("Modern Baseball", "Re-do", 6);
    Song d("Mom Jeans.", "Shred Cruz", 22);
    Song e("Mom Jeans.", "Death Cup", 14);
    Song f("Mom Jeans.", "Death Cup", 13);
    Song g("Tiny Moving Parts", "Always Focused", 24);
    Song h("Prince Daddy & the Hyena", "Really?", 11);
    Song i("American Football", "Honestly?", 10);
    Song j("The Front Bottoms", "Twin Size Mattress", 9);
    Song k("Pinegrove", "Old Friends", 6);
    Song l("Sorority Noise", "Blonde Hair, Black Lungs", 10);
    Song m("Tigers Jaw", "Plane vs. Tank vs. Submarine", 19);
    Song n("Remo Drive", "Yer Killin' Me", 14);
    Song o("Free Throw", "Two Beers In", 11);
    Song p("Snowing", "Sam Rudich", 3);
    Song q("Joyce Manor", "Constant Headache", 14);
    Song r("Moden Baseball", "Fine, Great", 513);
    Song s("Pinegrove", "Cadmium", 10);

    //testing Song functions and operators
    Song x;
    x.setTitle("Futura Free");
    x.setArtist("Frank Ocean");
    x.setSize(18);
    cout << x.getArtist() << endl;
    cout << x.getTitle() << endl;
    cout << x.getSize() << endl;
    if(a<b){
        cout << "< overload successful" << endl;
    }
    if(k>i){
        cout << "> overload successful" << endl;
    }
    if(a==e){
        cout << "== overload successful" << endl;
    }

    //test addSong function
    if(rock.addSong(a) == 0 && rock.addSong(b) == 0 && rock.addSong(c) == 0 && rock.addSong(c) == 0
    && rock.addSong(d) == 0 && rock.addSong(e) == 0 && rock.addSong(f) == 0 && rock.addSong(g) == 0
    && rock.addSong(h) == 0 && rock.addSong(i) == 0 && rock.addSong(j) == 0 && rock.addSong(k) == 0
    && rock.addSong(l) == 0 && rock.addSong(m) == 0 && rock.addSong(n) == 0 && rock.addSong(o) == 0
    && rock.addSong(p) == 0 && rock.addSong(q) == 0 && rock.addSong(x) == 0) {
        cout << "Adds successful" << endl;
    }
    else{
        cout << "addSong error" << endl;
    }

    //test removeSong function
    if(rock.removeSong(a) == 0 && rock.removeSong(b) == 0 && rock.removeSong(c) == 0 && rock.removeSong(c) == 0
       && rock.removeSong(d) == 0 && rock.removeSong(e) == 0 && rock.removeSong(f) == 0 && rock.removeSong(g) == 0
       && rock.removeSong(h) == 0 && rock.removeSong(i) == 0 && rock.removeSong(j) == 0 && rock.removeSong(k) == 0
       && rock.removeSong(l) == 0 && rock.removeSong(m) == 0 && rock.removeSong(n) == 0 && rock.removeSong(o) == 0
       && rock.removeSong(p) == 0 && rock.removeSong(q) == 0 && rock.removeSong(x) == 0) {
        cout << "Removes successful" << endl;
    }
    else{
        cout << "removeSong error" << endl;
    }

    //add a song with too much memory to test overflow handling
    if(rock.addSong(r) == -1){
        cout << "caught overflow" << endl;
    }
    else{
        cout << "ERROR: overflow memory" << endl;
    }

    //add songs back for further function testing
    rock.addSong(a);
    rock.addSong(b);
    rock.addSong(c);
    rock.addSong(d);
    rock.addSong(e);
    rock.addSong(f);
    rock.addSong(g);
    rock.addSong(h);
    rock.addSong(i);
    rock.addSong(j);
    rock.addSong(k);
    rock.addSong(l);
    rock.addSong(m);
    rock.addSong(n);
    rock.addSong(o);
    rock.addSong(p);
    rock.addSong(q);
    rock.addSong(s);
    rock.addSong(x);
    cout << endl;

    //tests showSongList function
    rock.showSongList();
    cout<<endl;

    //tests shuffle function
    rock.shuffle();
    rock.showSongList();
    cout<<endl;

    //test sortSongList function
    rock.sortSongList();
    rock.showSongList();

    //test getRemainingMemory function
    int num = rock.getRemainingMemory();
    if(num == 264){
        cout << "Correct memory remaining" << endl;
    }
    else{
        cout << "ERROR: getRemainingMemory" << endl;
    }

    //test getTotalMemory function
    num = rock.getTotalMemory();
    if(num == 512) {
        cout << "Correct total memory" << endl;
    }
    else{
        cout << "ERROR: getTotalMemory" << endl;
    }

    //test clearMemory function
    rock.clearMemory();
    if(rock.getRemainingMemory() == 512 && rock.getTotalMemory() == 512){
        cout << "correct clear" << endl;
    }
    else{
        cout << "clearMemory error" << endl;
    }
    cout << endl;
    rock.showSongList();

    //test removeSong without a song to remove
    if(rock.removeSong(a) == -2){
        cout << "correct response to song not found" << endl;
    }
    else{
        cout << "removeSong not found error" << endl;
    }

    // empty test case
    cout << "testing with a blank UtPod" << endl;
    UtPod blank(333);
    cout << "Blank Test Case" << endl;
    blank.showSongList();
    blank.shuffle();
    blank.showSongList();
    blank.sortSongList();
    blank.showSongList();
    blank.removeSong(a);
    cout << "Remaining mem: " << blank.getRemainingMemory() << endl;
    cout << "Total mem: " << blank.getTotalMemory() << endl;

    //empty constructor test
    UtPod emptyConstructor;
    if(emptyConstructor.getRemainingMemory() == 512){
        cout << "UtPod empty constructor works correctly" << endl;
    }
    else{
        cout<< "ERROR: UtPod empty constructor" << endl;
    }


    //small shuffle test
    cout << "Shuffle Test" << endl;
    UtPod shuffler(420);
    shuffler.addSong(a);
    shuffler.addSong(b);
    shuffler.addSong(c);
    shuffler.addSong(d);
    shuffler.addSong(g);

    shuffler.showSongList();

    cout << endl;
    cout << endl;
    shuffler.shuffle();
    shuffler.showSongList();

    return 0;


}