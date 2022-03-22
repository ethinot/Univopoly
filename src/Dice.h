#ifndef _DICE
#define _DICE

class Dice {

	private:

		unsigned int * values;

	public:

		Dice();
		void roll();
		bool checkDouble();
		unsigned int getTotal() const;
};

#endif