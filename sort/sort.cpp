#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) {}
    void reset() { m_begin = high_resolution_clock::now(); }
    //默认输出毫秒
    int64_t elapsed() const
    {
        return duration_cast<chrono::milliseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //微秒
    int64_t elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    } 
    //纳秒
    int64_t elapsed_nano() const
    {
        return duration_cast<chrono::nanoseconds>(high_resolution_clock::now() - m_begin).count();
    }
    //秒
    int64_t elapsed_seconds() const
    {
        return duration_cast<chrono::seconds>(high_resolution_clock::now() - m_begin).count();
    }
    //分
    int64_t elapsed_minutes() const
    {
        return duration_cast<chrono::minutes>(high_resolution_clock::now() - m_begin).count();
    }
    //时
    int64_t elapsed_hours() const
    {
        return duration_cast<chrono::hours>(high_resolution_clock::now() - m_begin).count();
    }
private:
    time_point<high_resolution_clock> m_begin;
};


int testTime()
{
    auto start = chrono::system_clock::now();
    this_thread::sleep_for(chrono::seconds(2)); 
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Elapse time is: " << double(duration.count())* chrono::microseconds::period::num/chrono::microseconds::period::den << "秒" << endl;
    return 0;
}

void dataPrint(vector<int> &data)
{
    for (auto v:data)
        cout << v << " ";
    cout << endl;
}

void bubleSort(vector<int> &data)
{
    auto len = data.size();
    auto flag = true;
    for (auto i = 0; flag && i < len; i++) {
        flag = false;
        for (auto j = 0; j < len - i - 1; j++) {
            if (data[j] > data[j+1]) {
                auto tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
                flag = true;
            }
        }
    }
}

void insertSort(vector<int> &data) 
{
    auto len = data.size();
    for (auto i = 1; i < len; i++) {
        auto j = i - 1;
        auto tmp = data[i];
        for (; j >= 0; j--) {
            if (data[j] <= tmp) //add = to keep stable
                break;
            data[j+1] = data[j];
        }
        data[j+1] = tmp;
    }
}

void selectSort(vector<int> &data) 
{
    auto len = data.size();
    for (auto i = 0; i < len; i++) {
        auto min = i;
        for (auto j = i + 1; j < len; j++) {
            if (data[j] < data[min])
                min = j;
        }
        if (i != min) {
            auto tmp = data[i];
            data[i] = data[min];
            data[min] = tmp;
        }
    }
}

void mergeSortData(vector<int> &data, int start, int end) 
{
    //cout << "start: " << start << ", end: "<< end << endl;
    //for (auto i = start; i <= end; i++) {
    //    cout << data[i] << " " ;
    //}
    //cout << endl;
    if (start >= end)
        return;
    auto mid = (start + end) / 2;
    mergeSortData(data, start, mid);
    mergeSortData(data, mid + 1, end);
    vector<int> tmp(end-start+1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    for (; i <= mid &&  j <= end; k++){
        if (data[i] < data[j]){
            tmp[k] = data[i];
            i++;
        } else {
            tmp[k] = data[j];
            j++;
        }
    }
    for (; i <= mid; i++, k++) 
        tmp[k] = data[i];
    for (; j <= end; j++, k++) 
        tmp[k] = data[j];
    for (auto i = start, j = 0; i <= end; i++, j++)
        data[i] = tmp[j];
    //cout << "Sorted start: " << start << ", end: "<< end << endl;
    //for (auto i = start; i <= end; i++) {
    //    cout << data[i] << " ";
    //}
    //cout << endl;

}

void mergeSort(vector<int> &data)
{
    mergeSortData(data, 0, data.size()-1);
}

void quickSortData(vector<int> &data, int start, int end)
{
    if (start >= end)
        return;

    //cout << "at first " << endl;
    //for (auto i = start; i <= end; i++) {
    //    cout << data[i] << " " ;
    //}
    //cout << endl;
    
    auto q = end;
    auto tmp = data[q];
    auto i = start;
    for (auto j = start; j < end; j++) {
        if (data[j] < tmp) {
            auto tdata = data[i];
            data[i] = data[j];
            data[j] = tdata;
            i++;
        }
    }
    auto tdata = data[i];
    data[i] = data[q];
    data[q] = tdata;
    q = i;

    //cout << "start: " << start << ", end: " << end << ", q: " << q << endl;
    //for (auto i = start; i <= end; i++) {
    //    cout << data[i] << " " ;
    //}
    //cout << endl;
    quickSortData(data, start, q - 1);
    quickSortData(data, q + 1, end);

}

void quickSort(vector<int> &data) 
{
    quickSortData(data, 0, data.size()-1);
}

int main()
{
//    Timer t; //开始计时
//    testTime();
//    cout<<t.elapsed()<<endl; //打印fun函数耗时多少毫秒
//    cout<<t.elapsed_micro ()<<endl; //打印微秒
//    cout<<t.elapsed_nano ()<<endl; //打印纳秒
//    cout<<t.elapsed_seconds()<<endl; //打印秒
//    cout<<t.elapsed_minutes()<<endl; //打印分钟
//    cout<<t.elapsed_hours()<<endl; //打印小时
    vector<int> data;
    srand((unsigned)time(0));
    for (auto i = 0; i < 10; i++) {
        data.push_back(rand()%100);
    }
    random_shuffle(data.begin(), data.end());
    auto d1 = data;
    auto d2 = data;
    auto d3 = data;
    auto d4 = data;
    auto d5 = data;

    dataPrint(data);
    mergeSort(data);
    dataPrint(data);
    quickSort(data);
    dataPrint(data);
    selectSort(data);
    dataPrint(data);
    insertSort(data);
    dataPrint(data);
    bubleSort(data);
    dataPrint(data);
    //dataPrint(d1);
    //quickSort(d2);
    //dataPrint(d2);
    //dataPrint(data);

//    Timer t1; //开始计时
//    bubleSort(d1);
//    cout<<t1.elapsed_micro ()<<endl; //打印微秒
//
//    Timer t2; //开始计时
//    insertSort(data);
//    cout<<t2.elapsed_micro ()<<endl; //打印微秒
//
//    Timer t3; //开始计时
//    selectSort(d3);
//    cout<<t3.elapsed_micro ()<<endl; //打印微秒
//
//    Timer t4; //开始计时
//    mergeSort(d4);
//    cout<<t4.elapsed_micro ()<<endl; //打印微秒
//
//    Timer t5; //开始计时
//    quickSort(d5);
//    cout<<t5.elapsed_micro ()<<endl; //打印微秒
//
}
