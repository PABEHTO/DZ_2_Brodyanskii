#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n,m;
    int neg1, neg2;
    int x, y = 0;
    double dist = 0;
    double rdist;
    int res;
    int i;
    int sum_points;
    while ((i & 5) != 5){  //кринж,но всё же ПОБИТОВЫЙ оператор
        i++;
        cout<<"Input x, y ";
        cin>>x; cin>>y;
        neg1 = rand()% 2; //рандом знака для x (- или +)
        neg2 = rand()% 2; //рандом знака для y (- или +)
        n = rand() % 5 + 1; // рандом беззнакового числа x
        n = n*(neg1-1) + n*((neg1+1)/2)*neg1; //рандомные числа от -5 до 5 для x
        m = rand() %5 + 1; // рандом беззнакового числа y
        m = m*(neg2-1) + m*((neg2+1)/2)*neg2; //рандомные числа от -5 до 5 для y
        x += n; y += m; //рандомные координаты
        dist = sqrt(pow(x,2) + pow(y,2)); //расстяние от начала координат до попадания
        rdist = floor(dist); //ну, так как радиусы [0,1),...,[4,5), то округлял вниз прост
        if (rdist < 5) {rdist = abs(rdist - 5); res+=rdist;} else rdist = 0; //преобразовывал расстояние в поинты через модуль
        //cout<<dist<<" "<<rdist<<" "<<res<<" "<<x<<" "<<y<<endl; //вспомогательная строка для того, чтобы видеть, что происходит
    }
    cout<<endl;
    sum_points = res;
    if (sum_points >= 10) cout<<sum_points; else cout<<sum_points<<" loser"<<endl;
    return 0;
}
