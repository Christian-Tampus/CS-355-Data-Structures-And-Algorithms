// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #0.5
// Date due: 01/12/2025
// Description: The program is designed to represent a polynomial using a linkedlist class data structure.
// ---------------------------------------------------------------------------
//Dependencies
#include "Poly.h"
//----------------------------------------------------------------------------
/* 
Description: Poly class constructor, sets head pointer to a nullptr
Incoming Data: None
Outgoing Data: None
*/
//----------------------------------------------------------------------------
Poly::Poly()
{
    head = nullptr;
};
//----------------------------------------------------------------------------
/* 
Description: Poly class constructor, takes one input other that is a Poly data type and sets head to nullptr then calls the private copyList(other) helper method
Incoming Data: other (Poly)
Outgoing Data: None
*/
//----------------------------------------------------------------------------
Poly::Poly(const Poly& other)
{
    head = nullptr;
    copyList(other);
};
//----------------------------------------------------------------------------
/*
Description: Poly class Extraction operator overload
Incoming Data: iStream (istream), inputPoly (Poly)
Outgoing Data: iStream (istream)
*/
//----------------------------------------------------------------------------
istream& operator>>(istream& iStream, Poly& inputPoly)
{
	//Reset inputPoly's linked list
	inputPoly.Reset();
	//Variable declarations
	char nextCharacterInput;
	std::string stringCoefficient;
	std::string stringExponent;
	int integerCoefficient;
	int integerExponent;
	//get '<' character first
	iStream >> nextCharacterInput;
	//first checks if input is in correct format of < [POLYNOMIAL] >
	if (nextCharacterInput != '<')
	{
		//if input is incorrect format, std::cout error message then return iStream
		std::cout << "ERROR IN INPUT FORMAT" << std::endl;
		return iStream;
	}
	//get first coefficient after '<'
	iStream >> nextCharacterInput;
	//loops until it reaches the end of the polynomial '>' (assuming that the polynomial is still in a correct format)
	while (nextCharacterInput != '>')
	{
		//resets both strings to an empty string so that it can be clear for the next term in the polynomial
		stringCoefficient = "";
		stringExponent = "";
		while (nextCharacterInput != 'x')
		{
			//loops until it reaches an 'x' character, appends each coefficient character to stringCoefficient until it reaches an 'x'
			stringCoefficient += nextCharacterInput;
			iStream >> nextCharacterInput;
		};
		//parses stringCoefficient to an integer
		integerCoefficient = std::stoi(stringCoefficient);
		//get '^' then get next exponent
		iStream >> nextCharacterInput;
		iStream >> nextCharacterInput;
		while (nextCharacterInput != '+' && nextCharacterInput != '>')
		{
			stringExponent += nextCharacterInput;
			iStream >> nextCharacterInput;
		};
		//parses stringExponent to an integer
		integerExponent = std::stoi(stringExponent);
		//insert both parsed integer coefficient & exponent as a new node in the inputPoly
		inputPoly.Insert(integerCoefficient,integerExponent);
		//check if the next character input is the end of the polynomial '>'
		if (nextCharacterInput != '>')
		{
			iStream >> nextCharacterInput;
		};
	};
    return iStream;
};
//----------------------------------------------------------------------------
/* 
Description: Poly class Insertion operator overload
Incoming Data: oStream (ostream), inputPoly (Poly)
Outgoing Data: oStream (ostream)
*/
//----------------------------------------------------------------------------
ostream& operator<<(ostream& oStream, const Poly& inputPoly)
{
	//variable declarations
	Term* currentTerm = inputPoly.head;
	//print out '<' first
	oStream << "<";
	while (currentTerm != nullptr)
	{
		std::cout << currentTerm->coefficient;
		//this handles print outs with 'x^' for terms that does not have 0 as an exponent
		if (currentTerm->exponent != 0)
		{
			std::cout << "x^" << currentTerm->exponent;
		};
		//adds a ' + ' in between terms as long as it has not reached the end of the linked list
		if (currentTerm->next != nullptr)
		{
			std::cout << " + ";
		};
		//traverser
		currentTerm = currentTerm->next;
	};
	//print out '>' last for the format < [POLYNOMIAL] >
	oStream << ">" << std::endl;
	return oStream;
};
//----------------------------------------------------------------------------
/* 
Description: Poly Reset() method
Incoming Data: None
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::Reset()
{
	//REFACTORED:
	//variable declarations
	Term* previousTerm = this->head;
	Term* currentTerm = this->head;
	//first checks if currentTerm is a nullptr (currentTerm is currently this->head), we do not need to set head to a nullptr if it already is a nullptr
	if (currentTerm != nullptr){
		//do while loop instead of a while loop since the head is already not a nullptr
		do
		{
			//deletion logic by deleting the previousTerm
			previousTerm = currentTerm;
			currentTerm = currentTerm->next;
			delete previousTerm;
		}while (currentTerm != nullptr);
		this->head = nullptr;
	};
	/* ORIGINAL:
	Term* current;
    Term* temp;
    current = head;
    while(current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
	*/
};
//----------------------------------------------------------------------------
/* 
Description: Poly Evaluate() method used to calculate the value of the polynomial by the integer input x
Incoming Data: x (Integer)
Outgoing Data: total (Integer)
*/
//----------------------------------------------------------------------------
int Poly::Evaluate(int x)
{
	//REFACTORED:
	//traverses the polynomial linked list and sums the total by the 'x' input value
	int total = 0;
	Term* currentTerm = this->head;
	while (currentTerm != nullptr)
	{
		total += (currentTerm->coefficient * std::pow(x, currentTerm->exponent));
		currentTerm = currentTerm->next;
	};
	return total;
	/* ORIGINAL:
	int val = 0;
	Term* current = head;
	while(current != nullptr)
	{
	    val = val + ((pow(x, current->exp))*current->coeff);
	    current = current->next;
	}
	return val;
	*/
};
//----------------------------------------------------------------------------
/* 
Description: Poly class Addition operator overload
Incoming Data: RHS (Poly)
Outgoing Data: totalPoly (Poly)
*/
//----------------------------------------------------------------------------
Poly Poly::operator+(const Poly& RHS)const
{
	//variable declarations
    Term* leftPoly = this->head;
    Term* rightPoly = RHS.head;
    Poly totalPoly;
    //loops until either leftPoly or rightPoly reached the end of its linked list
    while (leftPoly != nullptr && rightPoly != nullptr)
    {
    	//if both polynomials have the same exponent on the current term, insert the added values of the coefficients and either poly's exponent (in this case the left poly's exponent) then traverse both polynomials to the next term
		if (leftPoly->exponent == rightPoly->exponent)
    	{
    		totalPoly.Insert(leftPoly->coefficient + rightPoly->coefficient, leftPoly->exponent);
    		leftPoly = leftPoly->next;
    		rightPoly = rightPoly->next;
		}
		//we must insert whichever polynomial currently has the largest exponent until we get to the exponent that both polynomials have to perform an addition on (in this case if left poly is greater than right poly's exponent)
		else if (leftPoly->exponent > rightPoly->exponent)
		{
			totalPoly.Insert(leftPoly->coefficient, leftPoly->exponent);
			leftPoly = leftPoly->next;
		}
		//we must insert whichever polynomial currently has the largest exponent until we get to the exponent that both polynomials have to perform an addition on (in this case if left poly is less than right poly's exponent)
		else if (leftPoly->exponent < rightPoly->exponent)
		{
			totalPoly.Insert(rightPoly->coefficient, rightPoly->exponent);
			rightPoly = rightPoly->next;
		};
	};
	//once we reached the end of either polynomial's linked list, we must then insert the remaining terms of the polynomial that has not reached the end of its linked list
	//the while loop already checks if rightPoly or leftPoly is NOT a nullptr, if it is not, then it still has terms left to be inserted into the totalPoly
	//the extra if/else if statements are redundant
	//REFACTORED
	while (rightPoly != nullptr)
	{
		totalPoly.Insert(rightPoly->coefficient, rightPoly->exponent);
        rightPoly = rightPoly->next;
	}
	while (leftPoly != nullptr)
	{
		totalPoly.Insert(leftPoly->coefficient, leftPoly->exponent);
        leftPoly = leftPoly->next;
	};
	return totalPoly;
	/*ORIGINAL
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            sum.Insert(right->coeff, right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            sum.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return sum;
    */
};
//----------------------------------------------------------------------------
/* 
Description: Poly class Subtraction operator overload
Incoming Data: RHS (Poly)
Outgoing Data: totalPoly (Poly)
*/
//----------------------------------------------------------------------------
Poly Poly::operator-(const Poly& RHS)const
{
	//variable declarations
	Term* leftPoly = this->head;
	Term* rightPoly = RHS.head;
	Poly totalPoly;
	//loops until either leftPoly or rightPoly reached the end of its linked list
	while (leftPoly != nullptr && rightPoly != nullptr)
	{
		//if both polynomials have the same exponent on the current term, insert the subtracted values of the leftPoly by the rightPoly and either poly's exponent (in this case the left poly's exponent) then traverse both polynomials to the next term
		if (leftPoly->exponent == rightPoly->exponent)
		{
			int difference = leftPoly->coefficient - rightPoly->coefficient;
			if (difference != 0)
			{
				totalPoly.Insert(difference,leftPoly->exponent);
			}
			leftPoly = leftPoly->next;
			rightPoly = rightPoly->next;
		}
		//we must insert whichever polynomial currently has the largest exponent until we get to the exponent that both polynomials have to perform an subtraction on (in this case if left poly is greater than right poly's exponent)
		else if (leftPoly->exponent > rightPoly->exponent)
		{
			//since we are dependant of the leftpoly's term values, simply insert whatever value it currently is on the leftpoly to the totalpoly
			totalPoly.Insert(leftPoly->coefficient, leftPoly->exponent);
			leftPoly = leftPoly->next;
		}
		//we must insert whichever polynomial currently has the largest exponent until we get to the exponent that both polynomials have to perform an subtraction on (in this case if left poly is less than right poly's exponent)
		else if (leftPoly->exponent < rightPoly->exponent)
		{
			//since the rightpoly is the value that is being subtracted from the leftpoly we must subtract it from the rightpoly before inserting it by negating the coefficient
			totalPoly.Insert(-rightPoly->coefficient, rightPoly->exponent);
			rightPoly = rightPoly->next;
		};
	}
	
	//once we reached the end of either polynomial's linked list, we must then insert the remaining terms of the polynomial that has not reached the end of its linked list
	//the while loop already checks if rightPoly or leftPoly is NOT a nullptr, if it is not, then it still has terms left to be inserted into the totalPoly
	//the extra if/else if statements are redundant
	//REFACTORED
	while (rightPoly != nullptr)
	{
		//since the rightpoly is the value that is being subtracted from the leftpoly we must subtract it from the rightpoly before inserting it by negating the coefficient
		totalPoly.Insert(-rightPoly->coefficient, rightPoly->exponent);
        rightPoly = rightPoly->next;
	}
	while (leftPoly != nullptr)
	{
		//since we are dependant of the leftpoly's term values, simply insert whatever value it currently is on the leftpoly to the totalpoly
		totalPoly.Insert(leftPoly->coefficient, leftPoly->exponent);
        leftPoly = leftPoly->next;
	};
	return totalPoly;
	/*ORIGINAL
    if(left == nullptr && right != nullptr)
    {
        while(right != nullptr)
        {
            diff.Insert((-1*right->coeff), right->exp);
            right = right->next;
        }
    }
    else if(right == nullptr && left != nullptr)
    {
        while(left != nullptr)
        {
            diff.Insert(left->coeff, left->exp);
            left = left->next;
        }
    }
    return diff;
    */
};
//----------------------------------------------------------------------------
/* 
Description: Poly class Derivative method
Incoming Data: None
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::Derivative()
{
	/*
		Steps in handling 0 exponents if curr is NOT head
		step 1: if curr exponent == 0, check if head or not
		                                 prev    curr ->  next       
		(1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^0)->(1x^-1)
	    step 2: IF curr IS NOT head, set prev->next = curr->next
		                                 prev    curr ->  next 
	    (1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^0)->(1x^-1)
	    step 3: then delete curr           (at this point, both prev & curr is pointing to next)
		                                 prev     next    curr
	    (1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^-1)<-(1x^0)
	    step 4: set curr to prev->next
		                                 prev ->  next
	    (1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^-1)
	    step 5: repeat while loop
		                                 prev ->  curr
	    (1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^-1)
	    ----------------------------------------------------------------------------------------------------
	    Steps in handling 0 exponents if curr IS head
	    step 1: if curr exponent == 0, check if head or not
	     HEAD -> next
		 prev
		 curr -> next     
		(1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^0)->(1x^-1)
	    step 2: IF curr IS head, set TempTerm to this->head (prev), then set this->head = this->head.next
	     HEAD -> next
		 prev
		 curr -> next     
		(1x^5)->(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^0)->(1x^-1)
	    step 3: then delete TempTerm (which is currently prev)
	             HEAD -> next
    prev(null)
    curr(null)   
		(1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^0)->(1x^-1)
	    step 4: set prev & curr both to this->head
		 HEAD
         prev
		 curr -> next 
	    (1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^-1)
	    step 5: repeat while loop
	     HEAD
         prev
		 curr -> next 
	    (1x^4)->(1x^3)->(1x^2)->(1x^1)->(1x^-1)
    */
    //variable declarations
    Term* currentTerm = this->head;
    Term* previousTerm = this->head;
    Term* TempTerm = nullptr;
    //first checks if it is nessary to find the derivative if there is a term that exist in the linked list
    if (currentTerm != nullptr)
	{
		//traverses the entire linked list
		while (currentTerm != nullptr){
			// if the currentTerm's exponent is equal to 0
			if (currentTerm->exponent == 0)
			{
				//handle the deletion steps if currentTerm is a head or not
				if (currentTerm == this->head)
				{
					TempTerm = this->head;
					this->head = this->head->next;
					delete TempTerm;
					TempTerm = nullptr;
					previousTerm = this->head;
					currentTerm = this->head;
				}
				else
				{
					previousTerm->next = currentTerm->next;
					delete currentTerm;
					currentTerm = previousTerm->next;
				};
			}
			//if it currentTerm's exponent is not equal to 0, calculate its derivative by multiplying coefficient by the exponent and decrementing exponent before continuing to the next term node
			else
			{
				currentTerm->coefficient *= currentTerm->exponent;
				currentTerm->exponent--;
				previousTerm = currentTerm;
				currentTerm = currentTerm->next;
			};
		};
	};
	//The original solution is bugged/has issues
	//The original method only works for positive integer exponents, and fails to work for exponents with negative integers and will make negative integers disappear when the node that is connected before it reaches 0 and is deleted
	/* ORIGINAL
	Term* current;
    Term* previous;
    current = head;

    if(current!=nullptr)
    {
        if(current->exp == 0)
        {
            delete current;
            head = nullptr;
        }
        else if(current->next == nullptr)
        {
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
        }
        else{
            current->coeff = current->coeff * current->exp;
            current->exp = current->exp - 1;
            previous = current;
            current = current->next;
            while(current != nullptr)
            {
                if(current->exp == 0)
                {
                    previous->next = nullptr;
                    delete current;
                    current = nullptr;
                }
                else
                {
                    current->coeff = current->coeff * current->exp;
                    current->exp = current->exp - 1;
                    previous = current;
                    current = current->next;
                }
            }
        }
    }
    */
};
//----------------------------------------------------------------------------
/* 
Description: Insertion method for the polynomial, takes 2 inputs newCoefficient & newExponent and inserts the new term at the correct place
Incoming Data: newCoefficient (Integer), newExponent (Integer)
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::Insert(int newCoefficient, int newExponent)
{
	//REFACTORED
	//variable declarations
	Term* currentTerm = this->head;
    Term* previousTerm = this->head;
    Term* newTerm = new Term;
    newTerm->coefficient = newCoefficient;
    newTerm->exponent = newExponent;
    newTerm->next = nullptr;
    //if poly is empty, set to newTerm
    if (this->head == nullptr)
	{
		this->head = newTerm;
	}
	else
	{
		//traverse the linked list until currentTerm is a nullptr or newExponent is less than currentTerm's exponent
		while (currentTerm != nullptr && currentTerm->exponent > newExponent)
		{
			previousTerm = currentTerm;
			currentTerm = currentTerm->next;
		};
		//if currentTerm equals this->head (implying that it is not a nullptr and newExponent is less than or equal to the this->head->exponent) set newTerm->next to this->head then update this->head with newTerm
		if (currentTerm == this->head)
		{
			newTerm->next = this->head;
			this->head = newTerm;
		}
		else
		{
			//regardless currentTerm is a nullptr or not, you can directly set newTerm->next to currentTerm
			previousTerm->next = newTerm;
			newTerm->next = currentTerm;
		};
	};
	/*
	ORIGINAL
	Term* newT = new Term;
    newT->coeff = c;
    newT->exp = e;
    newT->next = nullptr;

    Term* current;
    Term* previous;

    if(head == nullptr)
    {
        head = newT;
    }
    else if(head->exp < e)
    {
        newT->next = head;
        head = newT;
    }
    else
    {
        current = head;

        while(current != nullptr && current->exp > e)
        {
            previous = current;
            current = current->next;
        }

        if(current == nullptr)
        {
            previous->next = newT;
        }
        else
        {
            previous->next = newT;
            newT->next = current;
        }
    }
    */
};
//----------------------------------------------------------------------------
/* 
Description: Searches the polynomial linked list to find the targetExponent and returns Term Pointer
Incoming Data: targetExponent (Integer)
Outgoing Data: SearchTerm (Term Pointer)
*/
//----------------------------------------------------------------------------
Term* Poly::Search(int targetExponent)
{
	Term* SearchTerm = this->head;
	//traverses the polynomial linked list nodes until it reaches the FIRST instance where the searchterm's exponent is equivalent to the targetExponent, then breaks out of the loop and returns the searchTerm
	while(SearchTerm != nullptr)
	{
		if (SearchTerm->exponent == targetExponent)
		{
			break;
		};
		SearchTerm = SearchTerm->next;
	};
	return SearchTerm;
};
//----------------------------------------------------------------------------
/* 
Description: Prints the polynomial terms in reverse order
Incoming Data: None
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::PrintReverse()
{
	//this will print the polynomial in reverse order in the format < [POLYNOMIAL] >
    Term* currentTerm = this->head;
    std::cout << "<";
    this->recPrintRev(this->head);
    std::cout << ">" << std::endl;
};
//----------------------------------------------------------------------------
/* 
Description: recursive helper function for PrintReverse()
Incoming Data: currentTerm (Term Pointer)
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::recPrintRev(Term* currentTerm)
{
	//if currentTerm is not an nullptr then call this->recPrintRev(currentTerm->next);
    if (currentTerm != nullptr)
	{	
		this->recPrintRev(currentTerm->next);
		//this will reach to the last node of the linked list then prints the last node first the the previous node and so on...
		std::cout << currentTerm->coefficient << "x^" << currentTerm->exponent << " + ";
	};
};
//----------------------------------------------------------------------------
/* 
Description: Assignment operator overload for the Poly class
Incoming Data: otherPoly (Poly)
Outgoing Data: *this (Poly)
*/
//----------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& otherPoly)
{
    //checks to make sure that this (current Poly) is not the same as the input poly (otherPoly) before calling the copyList() method
	if (this != &otherPoly)
    {
        this->copyList(otherPoly);
    }
	return *this;
};
//----------------------------------------------------------------------------
/* 
Description: Poly class destructor that calls the Reset() method
Incoming Data: None
Outgoing Data: None
*/
//----------------------------------------------------------------------------
Poly::~Poly()
{
    this->Reset();
};
//----------------------------------------------------------------------------
/* 
Description: Poly copyList() method
Incoming Data: otherList (Poly)
Outgoing Data: None
*/
//----------------------------------------------------------------------------
void Poly::copyList(const Poly& otherList)
{
	//variable declarations
	Term* newTerm = nullptr;
	Term* otherListCurrentTerm = otherList.head;
	Term* thisListCurrentTerm = nullptr;
	//modified reset so that it checks if head is nullptr
	this->Reset();
	if (otherListCurrentTerm == nullptr)
	{
		this->head = nullptr;
	}
	else
	{
		//set this->head coefficient & exponent from otherList head
		this->head = new Term;
		this->head->coefficient = otherListCurrentTerm->coefficient;
		this->head->exponent = otherListCurrentTerm->exponent;
		this->head->next = nullptr;
		thisListCurrentTerm = this->head;
		otherListCurrentTerm = otherListCurrentTerm->next;
		//this while loop is used to set the coefficient & exponent for every other node BUT the head
		while (otherListCurrentTerm != nullptr)
		{
			newTerm = new Term;
			newTerm->coefficient = otherListCurrentTerm->coefficient;
			newTerm->exponent = otherListCurrentTerm->exponent;
			newTerm->next = nullptr;
			//append the newTerm after updating its coefficient, exponent & next values
			thisListCurrentTerm->next = newTerm;
			//traversals
			thisListCurrentTerm = thisListCurrentTerm->next;
			otherListCurrentTerm = otherListCurrentTerm->next;
		};
	};
};