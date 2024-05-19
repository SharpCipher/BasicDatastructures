#include <iostream>
#include <cstdint>

using namespace std;

enum class days:std::int8_t
{SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};

ostream& operator<<(ostream& out, const days& d){
    
    out << static_cast<int>(d);
    return out;
}

days operator++(days& d){
    d = static_cast<days>((static_cast<int>(d) + 1) % 7 );
    return d;
}

days operator++(days& d, int){
    days temp = d;
    d = static_cast<days>((static_cast<int>(d) + 1) % 7);
    return temp;
}

int main(){
    
    days today{days::MONDAY};
    cout << "Demo on class enum"<<endl;
    cout << "MONDAY value is "<< today <<endl;
    cout << "Increment value is "<< ++today <<endl;
    cout << "Increment value is "<< today++ <<endl;
    cout << "Increment value is "<< today <<endl;
    
    return 0;
}
