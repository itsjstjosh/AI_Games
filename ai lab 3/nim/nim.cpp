#include <iostream>

template <unsigned int num_heaps = 3>
class nim
{
public:
  unsigned int state_[num_heaps];

  nim(unsigned int n1, unsigned int n2, unsigned int n3) : state_{n1,n2,n3}
  {
  }

  void play()
  {
    std::cout << std::endl;

    while (true)
    {
      std::cout << std::endl;

      for (unsigned heap_id = 0; heap_id < num_heaps; heap_id++)
      {
        std::cout << "heap " << heap_id << ": ";
        for (unsigned i = 0; i < state_[heap_id]; i++)
        {
          std::cout << '*';
        }

        std::cout << std::endl;
      }

      if (human_move() == false)
        continue;  // human tried an illegal move; return to while loop start

      if (0 == stones_remaining())
      {
        std::cout << "Computer has won! The singularity is near.\n";
        break; // exit the while loop
      }

      computer_move();

      if (0 == stones_remaining())
      {
        std::cout << "Human has won! The singularity is far.\n";
        break; // exit the while loop
      }
    };
  }

  unsigned int stones_remaining()
  {
    unsigned int total = 0;
    for (auto nstones : state_)
    {
      total += nstones;
    }
    return total;
  }

  bool human_move()
  {
    unsigned int heap_id{}, nremove{};

    std::cout << "\nSelect a heap (0-" << (num_heaps-1) << "):\n";
    std::cin >> heap_id;
    if (heap_id >= num_heaps)
    {
      std::cout << "Oops! Try again..." << std::endl;
      return false;
    }
    std::cout << "Remove how many stones? (max " << state_[heap_id] << ")\n";
    std::cin >> nremove;
    if (nremove > state_[heap_id] || nremove == 0)
    {
      std::cout << "Oops! Try again..." << std::endl;
      return false;
    }
    state_[heap_id] -= nremove;
    return true;
  }

  void computer_move()
  {
    // does nothing so far
  }

};

int main(int argc, char *argv[])
{
  nim<3> n{3,4,5};
  n.play();

  return 0;
}
