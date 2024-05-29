#include "StackType.h"
#include "QueType.h"
#include <string>
#include <iostream>

// Function to decode a string based on a code string
std::string decode(std::string exp, std::string code) {
  // Create stack to store characters for reversal
  StackType<char> stack;
  // Create queue to assist in reversing characters in controlled manner
  QueType<char> queue;
  // String to store the decoded output
  std::string output;

  // Iterate through each character in the expression string
  for (char c : exp) {
    // Check if character is not present in the code string
    if (code.find(c) == std::string::npos) {
      // Append character directly to the output (normal order)
      output += c;
    } else {
      // Push character onto the stack for later reversal
      stack.Push(c);
    }
  }

  // While the stack is not empty
  while (!stack.IsEmpty()) {
    // Access the top element without using front (pop and enqueue)
    char top = stack.Pop(); // Remove top element from stack
    queue.Enqueue(top); // Add top element to the back of the queue
  }

  // Append characters from the queue to the output in reverse order
  while (!queue.IsEmpty()) {
    char item;
    queue.Dequeue(item); // Remove and store the front element
    output += item;
  }

  // Return the decoded string
  return output;
}

