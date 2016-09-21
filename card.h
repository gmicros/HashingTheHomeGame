#include <string>

class Card {
	public:
		/* 
		 * Default Constructor
		 *
		 * Initilizes all non-pointer types to a default value and all pointer types to NULL;
		 */
		Card();
		
		/*
		 * Copy Constructor
		 * 
		 * Initiliazes all non-pointer types with the values from the passed in Card
		 * For pointers, initilizes a new memory space that contains the values from 
		 * the passed in Card pointer
		 */ 
		Card(const Card& c);		
				
		/*
		 * Destructor 
		 * Deletes all defined pointers
		 */
		~Card();

		Card& operator=(Card rhs);

		void swap(Card& c);

		std::string getTitle();
		void setTitle(std::string newTitle);

		std::string getDesc();
		void setDesc(std::string newDesc);

		int getNoSpacesToMove();
		void setNoSpacesToMove(int numSpaces);
	
		int getNoTurnsToSkip();
		void setNoTurnsToSkip(int numTurns);

		bool getRollAgain();
		void setRollAgain(bool reRoll); 
	private:
		std::string title;
		std::string desc;
		int noSpacesToMove;
		int noTurnsToSkip;
		bool rollAgain;	
};
