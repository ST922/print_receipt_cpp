/*
You will create user-defined data types and use them to collect order information from a 
customer.  Using a control loop, get order information from the customer and then display the 
total order when the customer is finished.
*/

// CSIS 111-D02

//Include statements 
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Function Prototypes
double getCost(char type, int amount, double width, double height, double length);

// Main Function
int main()
{
    // In cout statement below SUBSTITUTE  your name and lab number
    cout << "Samuel Teigland -- 5" << endl;
    cout << endl;

	//variable declarations
	int amount;
	double total, cost, width, length, height;
	char type;
    int counter = 0; // Counter is used in do-while loop to determine
                     // the message that is shown to the user based on
                     // the number of times that they have entered.
    // Set total equal to 0
    total = 0;

    // Program logic
    /* 
        I used a do-while loop here because I want it to keep iterating and then check to make sure that
        specific conditions are being met. For example, iterate and then make sure that the user doesn't
        want to terminate the program by activating the sentinel character 'T'.
    */
	do
	{
        // Check the entry of the user and change based on the number of entries
        if (counter < 1) // Counter used here
        {
            cout << "Please enter item: "; // Message for first entry
	        cin >> type;
        }
        else if (counter > 0) // Counter used here
        {
            cout << "Enter another item (or press T for the total): "; // Message for second entry
            cin >> type;
        }

        // Terminate the program and show the total cost if the user activates the sentinel
		if (type == 'T' || type == 't')
		{
			cout << "Total cost: " << fixed << setprecision(2) << total << endl;
			return 0;
		}

        // While the type of the wood is incorrect keep asking the user to input a valid character
        // Additionally, if the user inputs the sentinel, output the total cost and terminate the program
		while (type != 'P' && type != 'F' && type != 'C' && type != 'M' && type != 'O'&& type != 'p' && type != 'f' && type != 'c' && type != 'm' && type != 'o')
		{
            // Check for invalid entry
			cout << "Invalid selection. Please try again." << endl; // Invalid message
			cout << "Please enter item: ";
			cin >> type;

            // Sentinel
			if (type == 'T' || type == 't')
			{
				cout << "Total cost: " << fixed << setprecision(2) << total << endl;
				return 0;
			}
		}

        // Asking the user to input the amout of pieces that they have
		cout << "Enter the number of boards: ";
		cin >> amount;

        // Check and make sure that amount is a valid entry.
        // Amount cannot be less than 0.  While the user inputs and invalid
        // number, keep asking them to input a valid number.
        // Stop once amount is greater than 0.
        while (amount <= 0)
        {
            cout << "Invalid entry. Please select a number greater than 0." << endl;
            cout << "Enter the number of boards: ";
            cin >> amount;
        }

        // Enter dimensions in the following order width, height, length
		cout << "Enter the demensions in inches (width, height, length): ";
		cin >> width >> height >> length;

        // Get the cost from getCost() function
		cost = getCost(type, amount, width, length, height);

        // Continues the text started in the getCost() function and outputs the cost to the user
		cout << " at a cost of " << fixed << setprecision(2) << cost << endl;
		cout << endl;

        // Everytime the program iterates, add cost to the total.
		total += cost;

        // Counter increases everytime the program iterates to ensure that the
        // correct message is shown to the user at the beginning of the program.
        counter++;

	} while (type != 'T'); // Execute the program and then check to ensure that type != 'T'
                           // If it does, display total and terminate.

    // Closing program statements
	return 0;

}

// getCost() is used for finding the cost of the materials and sending it to int main()
double getCost(char type, int amount, double width, double height, double length)
{
    // Defining variables that aren't shared between getCost() and main()
	double cost;
	string type1; // Turns char type into a string called type1
	cost = (width * height * length) / 12; // Equation for finding cost
	cost = amount * cost; // Multiplying the cost by the amount found in main()

    // If statement to check and assign the right cost and string to the material entered
    // by the user.
    // Pine
	if (type == 'P' || type == 'p')
	{
		type1 = "pine";
		cost = cost * 0.89;
	}
    // Fir
	else if (type == 'F' || type == 'f')
	{
		type1 = "fir";
		cost = cost * 1.09;
	}
    // Cedar
	else if (type == 'C' || type == 'c')
	{
		type1 = "cedar";
		cost = cost * 2.26;
	}
    // Maple
	else if (type == 'M' || type == 'm')
	{
		type1 = "maple";
		cost = cost * 4.50;
	}
    // Oak
	else if (type == 'O' || type == 'o')
	{
		type1 = "oak";
		cost = cost * 3.10;
	}

    // Output statement that shows the amount purchased, dimensions and the name of the material
    // to the user. The rest of the output is then returned to the main() function and continued there.
	cout << amount << " " << fixed << setprecision(0) << width << "x" << height << "x" << length << " of " << type1;

    // Closing function statements
    // Returns cost back to int main()
	return cost;

}
