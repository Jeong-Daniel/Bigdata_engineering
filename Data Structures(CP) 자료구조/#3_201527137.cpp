#include <iostream>
using namespace std;

class Polynomial;
class Term{
	friend Polynomial;
	private:
		int coe;
		int exp;
};

class Polynomial{
	private:
		Term *tArray;
		int termCnt;
		int flag;
	public:
		
	Polynomial(int n): termCnt(n){
		flag=0;
		tArray = new Term[termCnt];
		for(int i=0;i<termCnt;i++)
		{
			cin >> tArray[i].coe >> tArray[i].exp;
		}
	}
	
	Polynomial(Term *tempArr, int n): termCnt(n){
		flag = 0;
		tArray = new Term[termCnt];
		for(int i=0; i<termCnt ; i++)
		{
			tArray[i].coe = tempArr[i].coe;
			tArray[i].exp = tempArr[i].exp;
		}
	}
	
	Polynomial operator +(Polynomial p){
		int twoLen = this->termCnt + p.termCnt;
		int realLen = 0;
		Term *tempArr = new Term[twoLen];
		for(int i =0; i<twoLen ; i++)
		{
			if(this->flag == this->termCnt)
			{
				if(p.flag == p.termCnt)
				{
					break;
				}
				else{
					tempArr[i].coe = p.tArray[p.flag].coe;
					tempArr[i].exp = p.tArray[p.flag].exp;
					p.flag++;
				}
			}
			else if(p.flag == p.termCnt)
			{
				tempArr[i].coe = this -> tArray[this->flag].coe;
				tempArr[i].exp = this -> tArray[this->flag].exp;
				this->flag++;
			}
			else{
				if(this->tArray[this->flag].exp > p.tArray[p.flag].exp)
				{
					tempArr[i].coe = this -> tArray[this->flag].coe;
					tempArr[i].exp = this -> tArray[this->flag].exp;
					this->flag++;
				}
				else if(this->tArray[this->flag].exp < p.tArray[p.flag].exp){
					tempArr[i].coe = p.tArray[p.flag].coe;
					tempArr[i].exp = p.tArray[p.flag].exp;
					p.flag++;
				}
				else{
					tempArr[i].coe = (this->tArray[this->flag].coe) + (p.tArray[p.flag].coe);
					tempArr[i].exp = p.tArray[p.flag].exp;
					this->flag++;
					p.flag++;
				}
			}
			realLen++;
		}
		Polynomial pSum(tempArr, realLen);
		return pSum;
	}
	
	Polynomial operator *(Polynomial p){
		Term *tempArr1 = new Term[p.termCnt];
		Term *tempArr2 = new Term[p.termCnt];
		for(int i =0; i< p.termCnt ; i++)
		{
			tempArr1[i].coe = (this->tArray[0].coe)*(p.tArray[i].coe);
			tempArr1[i].exp = (this->tArray[0].exp)+(p.tArray[i].exp);
		}
		Polynomial pMul(tempArr1, p.termCnt);
		for(int i = 0 ; i< this->termCnt ; i++)
		{
			for(int j=0; j< p.termCnt ; j++)
			{
				tempArr2[j].coe = (this->tArray[i].coe) * (p.tArray[j].coe);
				tempArr2[j].exp = (this->tArray[i].exp) + (p.tArray[j].exp);
			}
			Polynomial tmpPoly(tempArr2, p.termCnt);
			pMul = pMul + tmpPoly;
		}
		return pMul;
	}
	
	void printPoly(){
		cout << termCnt;
		for(int i=0 ; i<termCnt;i++)
		{
			cout << " " << tArray[i].coe << " " << tArray[i].exp;
		}
		cout<<endl;
	}
};

int main()
{
	int p1n, p2n;
	cin >> p1n;
	Polynomial p1(p1n);
	cin >> p2n;
	Polynomial p2(p2n);
	
	Polynomial p3 = p1 * p2;
	p3.printPoly();
}
