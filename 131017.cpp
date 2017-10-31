//MATERI HARI INI: 16 okt 2017 Fungsi Sorting...
//minggu lalu 
//struct : pasti public, versi jadul, tapi bagus buat kompetisi
//class : bisa public or private, better than struct, buat project 
// c++ punya fungsi buat ngurtuin

//SORTING NON-KELAS
//1.
#include<stdio.h>//punya  C
#include<algorithm>//punya C++
#include<functional>// buat ngurutin descending
//tuliskan
using namespace std;
//kalau pake method yang udah ada di library , error
//misalnya ada dua orang ngerjin library berbeda
//ada kemungkinan bentrok( nama nya sama)
//artinya : "janjian" pake nama std.
// nama variabel ga boleh ada yang sama dengan di library C++

//kalau ga ada, pake std :: (namafungsi)

//mirip nge-import package di Java
//kelas boleh namanya sama , ASAL gak di package yang sama

//karena kompetisi ga usah pake yg lain
class Point{
	public:
	int x,y;
	
	Point(int x,int y){
		this->x = x;
		this->y = y;
	}
	
	moveBy(int deltaX,int deltaY){
		this->x += deltaX;
		this->y += deltaY;
	}
	
	//buat ngebandingin
	//operator overloading
	bool operator<(Point other) const{
		if(x == other.x)
			return (y < other.y);
		else
			return (x < other.x);
	}
	
	//buat ngebandingin
	//operator overloading
	bool operator>(Point other) const{
		if(x == other.x)
			return (y > other.y);
		else
			return (x > other.x);
	}
};

int main(){
	int arr[5] = { 5, 3 ,1 ,2 ,6};
	Point arr[5]
	sort(arr,arr+5);//cukup pinter, udah tau apa yang di sorting, entah itu object
	//arr    | 5 | 3  | 1 | 2 | 6 | ..... |  
	//                              arr+ 5 (ujung eksklusif)
	//keunggulannya, kita bisa nentuin daerah mana aja yang disort.
	
	//ini sih standar.. (ascending)
	//kalau mau menurun, tambahkan parameter ketiga , yaitu fgs buat ngebandingin
	//atau pake library khusus, --functional--
	sort(arr,arr+5, less<int>() );
	/**
	
	* dia bisa ngurutin tipe data apapun yang di dalam kurung siku
	* by default, yang kecil di depan
	* kalau pake greater, yang gede di depan
	*/
	for(int i = 0 ;i < 5 ; i++){
		printf("%d ",arr[i]);
	}
	return 0;
}