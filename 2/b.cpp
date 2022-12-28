#include <dirent.h>
#include <iostream>
#include <unistd.h>  // for sleep()

int main() {
  while (true) {
    // Open the "./directory" directory
    DIR* directory = opendir("./directory");
    if (directory == NULL) {
      // An error occurred while trying to open the directory
      std::cout << "Error opening directory" << std::endl;
      return 1;
    }

    // Iterate over all the entries in the directory
    dirent* entry;
    while ((entry = readdir(directory)) != NULL) {

      if (entry->d_type == DT_REG) {
        std::cout << "Process " << entry->d_name << std::endl;
        remove(("./directory/" + std::string(entry->d_name)).c_str());
      }
    }

    // Close the directory
    closedir(directory);

    // Sleep for 5 seconds
    sleep(5);
  }

  return 0;
}