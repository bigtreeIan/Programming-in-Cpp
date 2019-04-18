/*
 * Coins.h
 *
 *  Created on: 2016年1月20日
 *      Author: xuyihan
 */
#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
  Coins( int q, int d, int n, int p ){
	  quarters = q;
	  dimes = d;
	  nickels = n;
	  pennies = p;
  }
  void depositChange( Coins & c ){
	  quarters += c.quarters;
	  dimes += c.dimes;
	  nickels += c.nickels;
	  pennies += c.pennies;
	  c.quarters = 0;
	  c.dimes = 0;
	  c.nickels = 0;
	  c.pennies = 0;
  }
  bool hasSufficientAmount( int amount ){
	  return (quarters * 25 + dimes * 10 + nickels * 5 + pennies >= amount);
  }
  Coins extractChange(int amount){
	  if(amount < 5){
		  int used_quarters = 0;
		  int used_dimes = 0;
		  int used_nickels = 0;
		  int used_pennies = amount;
		  quarters = (quarters - used_quarters);
		  dimes = (dimes - used_dimes);
		  nickels = (nickels - used_nickels);
		  pennies = (pennies - used_pennies);
		  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
	  }
	  else if (amount >= 5 and amount < 10){
		  int used_quarters = 0;
		  int used_dimes = 0;
		  int used_nickels = amount / 5;
		  int left_amount = amount % 5;
		  int used_pennies = left_amount;
		  quarters = quarters - used_quarters;
		  dimes = dimes - used_dimes;
		  nickels = nickels - used_nickels;
		  pennies = pennies - used_pennies;
		  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
	  }
	  else if (amount >= 10 and amount < 25){
		  int used_quarters = 0;
		  int used_dimes = amount / 10;
		  int left_amount = amount % 10;
		  if (left_amount >= 5){
			  int used_nickels = left_amount / 5;
			  left_amount = left_amount % 5;
			  int used_pennies = left_amount;
			  quarters = quarters - used_quarters;
			  dimes = dimes - used_dimes;
			  nickels = nickels - used_nickels;
			  pennies = pennies - used_pennies;
			  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
		  }
		  else if (left_amount < 5){
			  int used_nickels = 0;
			  int used_pennies = left_amount;
			  quarters = quarters - used_quarters;
			  dimes = dimes - used_dimes;
			  nickels = nickels - used_nickels;
			  pennies = pennies - used_pennies;
			  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
		  }
	  }
	  else if(amount > 25){
		  int used_quarters = amount / 25;
		  int left_amount = amount % 25;
		  if (left_amount >= 10){
			  int used_dimes = left_amount / 10;
			  int left_amount_x = left_amount % 10;
			  if (left_amount_x < 5){
				  int used_nickels = 0;
				  int used_dimes = 0;
				  int used_pennies = left_amount_x;
				  quarters = quarters - used_quarters;
				  dimes = dimes - used_dimes;
				  nickels = nickels - used_nickels;
				  pennies = pennies - used_pennies;
				  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
			  }
			  else if (left_amount >= 5){
				  int used_nickels = left_amount / 5;
			 	  int left_amount_y = left_amount % 5;
			  	  int used_pennies = left_amount_y;
				  quarters = quarters - used_quarters;
		  		  dimes = dimes - used_dimes;
		  		  nickels = nickels - used_nickels;
		  		  pennies = pennies - used_pennies;
			  	  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
			  }
		  }
		  else if (left_amount < 10 and left_amount >= 5){
			  int used_nickels = (left_amount / 5);
			  int left_amount_z = (left_amount % 5);
			  int used_dimes = 0;
			  int used_pennies = left_amount_z;
			  quarters = quarters - used_quarters;
			  dimes = dimes - used_dimes;
			  nickels = nickels - used_nickels;
			  pennies = pennies - used_pennies;
			  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
		  }
		  else if (left_amount < 5)	{
			  int used_pennies = left_amount;
			  int used_dimes = 0;
			  int used_nickels = 0;
			  quarters = quarters - used_quarters;
			  dimes = dimes - used_dimes;
			  nickels = nickels - used_nickels;
			  pennies = pennies - used_pennies;
			  return Coins(used_quarters, used_dimes, used_nickels, used_pennies);
		  }
	  }
  }
  void print( ostream & out ){
	  out << quarters << " [Quarters]" << ", "<< dimes << " [Dimes]" << ", "<< nickels << " [Nickels]" << ", " << pennies << "[Pennies]";
  }
private:
  int quarters, dimes, nickels, pennies;
};
ostream & operator << ( ostream & out, Coins & c ){
	c.print(out);
	return out;
}
