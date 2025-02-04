#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::ios;

// Near-minimal UCI Chess Engine. Derived from:
// From: https://ucichessengine.wordpress.com/2011/03/16/c-chess-engine-uci/

int main(int argc, char *argv[])
{
  string line;  // to read the command given by the GUI
  std::ofstream debug("debug.txt");
  char col = 'a';

  // Make sure that the outputs are sent straight away to the GUI
  cout.setf(ios::unitbuf);

  while (getline(cin, line)) {
//      debug << line << '\n';
//    debug << "::" << line.substr(0,23) << "::" << '\n';
    if (line == "uci") {
      cout << "id name Demo_engine" << '\n';
      cout << "id author XXX" << '\n';
      cout << "uciok" << '\n';
    } else if (line == "quit") {
      cout << "Bye Bye" << '\n';
      break;
    } else if (line == "isready") {
      cout << "readyok" << '\n';
    } else if (line == "ucinewgame") {
      col = 'a'; // Bingo, a fresh start for our mighty engine!
    }

    // The full state of play follows "moves"; e.g. 
    if (line.substr(0,23) == "position startpos moves") {
      ; // nothing to do
      debug << line << '\n';
    } else if (line == "stop") {
      ; // nothing to do
    } else if (line.substr(0, 3) == "go " ) {
      // Received a command like: "go wtime 300000 btime 300000 winc 0 binc 0"
      cout << "bestmove " << col << '7';
      cout                << col << '5' << '\n';
      // Output like: "bestmove a7a5"
      col++;
    }
  }

  return 0;
}
