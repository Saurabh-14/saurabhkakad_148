#include <iostream>
#include <string>
#include <limits>
using namespace std;
// Node class representing one song
class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = NULL;
        next = NULL;
    }
};
// Doubly Linked List for Music Playlist
class MusicPlaylist {
private:
    Node* head;       // Points to the first song
    Node* current;    // Points to the currently selected song
public:
    MusicPlaylist() {
        head = NULL;
        current = NULL;
    }
    // Add a new song at the end
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist); // p is the new node

        if (head == NULL) {
            head = p;
            current = p;
        } else {
            Node* q = head; // q traverses the list

            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
        cout << "Song added successfully!\n";
    }
    // Delete a song by its title
    void deleteSong(string title) {
        Node* p = NULL;
        Node* q = head;
        // Find the song to delete
        while (q != NULL && q->title != title) {
            q = q->next;
        }

        if (q == NULL) {
            cout << "Song not found!\n";
            return;
        }
        p = q; // p points to the node being deleted
        // Update current if the selected song is deleted
        if (current == p) {
            if (p->next != NULL)
                current = p->next;
            else
                current = p->prev;
        }
        // Connect the previous node to the next node
        if (p->prev != NULL)
            p->prev->next = p->next;
        else
            head = p->next;
        // Connect the next node to the previous node
        if (p->next != NULL)
            p->next->prev = p->prev;
        delete p;
        cout << "Song deleted successfully!\n";
    }
    // Display playlist from first to last
    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }
        Node* q = head;
        cout << "\n--- Music Playlist ---\n";
        while (q != NULL) {
            cout << q->title << " - " << q->artist << '\n';
            q = q->next;
        }
    }
    // Display playlist from last to first
    void displayReverse() {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }
        Node* q = head;
        // Move q to the last song
        while (q->next != NULL) {
            q = q->next;
        }
        cout << "\n--- Reverse Playlist ---\n";

        while (q != NULL) {
            cout << q->title << " - " << q->artist << '\n';
            q = q->prev;
        }
    }
    // Play the currently selected song
    void playCurrentSong() {
        if (current == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }
        cout << "Now Playing: " << current->title
             << " - " << current->artist << '\n';
    }
    // Move to the next song
    void playNextSong() {
        if (current == NULL) {
            cout << "Playlist is empty!\n";
        } else if (current->next == NULL) {
            cout << "You are already at the last song!\n";
        } else {
            current = current->next;
            playCurrentSong();
        }
    }
    // Move to the previous song
    void playPreviousSong() {
        if (current == NULL) {
            cout << "Playlist is empty!\n";
        } else if (current->prev == NULL) {
            cout << "You are already at the first song!\n";
        } else {
            current = current->prev;
            playCurrentSong();
        }
    }
    // Show the complete playlist as playback
    void playCompletePlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }
        current = head;
        Node* q = head;
        cout << "\n--- Playing Complete Playlist ---\n";
        while (q != NULL) {
            current = q;
            playCurrentSong();
            q = q->next;
        }
    }
    // Play the complete playlist a specified number of times
    void repeatAll(int repetitions) {
        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }
        if (repetitions <= 0) {
            cout << "Enter a positive number of repetitions!\n";
            return;
        }
        for (int i = 1; i <= repetitions; i++) {
            cout << "\nRepetition " << i << ":\n";
            playCompletePlaylist();
        }
        cout << "Repeat All completed!\n";
    }
    // Display the currently selected song
    void showCurrentSong() {
        if (current == NULL) {
            cout << "No song selected!\n";
        } else {
            cout << "Current Song: " << current->title
                 << " - " << current->artist << '\n';
        }
    }
    // Free all allocated memory
    ~MusicPlaylist() {
        Node* q = head;
        while (q != NULL) {
            Node* p = q;
            q = q->next;
            delete p;
        }
        head = NULL;
        current = NULL;
    }
};
int main() {
    MusicPlaylist playlist;
    int choice;
    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string title, artist;
        int repetitions;

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);

                cout << "Enter artist name: ";
                getline(cin, artist);

                playlist.addSong(title, artist);
                break;
            case 2:
                cout << "Enter title of song to delete: ";
                getline(cin, title);
                playlist.deleteSong(title);
                break;
            case 3:
                playlist.displayPlaylist();
                break;
            case 4:
                playlist.displayReverse();
                break;
            case 5:
                playlist.playCurrentSong();
                break;
            case 6:
                playlist.playNextSong();
                break;
            case 7:
                playlist.playPreviousSong();
                break;
            case 8:
                playlist.playCompletePlaylist();
                break;
            case 9:
                cout << "Enter number of repetitions: ";
                if (!(cin >> repetitions)) {
                    cout << "Invalid repetition count!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(), '\n'
                    );
                    break;
                }
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );
                playlist.repeatAll(repetitions);
                break;
            case 10:
                playlist.showCurrentSong();
            break;
            case 11:
                cout << "Exiting Music Playlist Manager.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 11);
    return 0;
}

/*PS C:\Users\HP> cd "d:\MusicPlaylistProject\" ; if ($?) { g++ main.cpp -o main } ; if ($?) { .\main }

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: Tum Hi Ho
Enter artist name: Jubin Nautiyal
Song added successfully!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: Raataan Lambiyan
Enter artist name: Asees Kaur
Song added successfully!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: Heeriye
Enter artist name: Jasleen Royal
Song added successfully!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: Apna Bana Le
Enter artist name: Arijit Singh
Song added successfully!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 2
Enter title of song to delete: Raataan Lambiyan
Song deleted successfully!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 3

--- Music Playlist ---
Tum Hi Ho - Jubin Nautiyal
Heeriye - Jasleen Royal
Apna Bana Le - Arijit Singh

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 4

--- Reverse Playlist ---
Apna Bana Le - Arijit Singh
Heeriye - Jasleen Royal
Tum Hi Ho - Jubin Nautiyal

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 5
Now Playing: Tum Hi Ho - Jubin Nautiyal

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 6
Now Playing: Heeriye - Jasleen Royal

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 7
Now Playing: Tum Hi Ho - Jubin Nautiyal

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 8

--- Playing Complete Playlist ---
Now Playing: Tum Hi Ho - Jubin Nautiyal
Now Playing: Heeriye - Jasleen Royal
Now Playing: Apna Bana Le - Arijit Singh

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 9
Enter number of repetitions: 2

Repetition 1:

--- Playing Complete Playlist ---
Now Playing: Tum Hi Ho - Jubin Nautiyal
Now Playing: Heeriye - Jasleen Royal
Now Playing: Apna Bana Le - Arijit Singh

Repetition 2:

--- Playing Complete Playlist ---
Now Playing: Tum Hi Ho - Jubin Nautiyal
Now Playing: Heeriye - Jasleen Royal
Now Playing: Apna Bana Le - Arijit Singh
Repeat All completed!

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 10
Current Song: Apna Bana Le - Arijit Singh

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 11
Exiting Music Playlist Manager.
PS D:\SaurabhKakadMusicPlaylistProject> */