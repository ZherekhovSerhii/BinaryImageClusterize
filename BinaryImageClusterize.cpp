#include <iostream>
#include <map>

void Clusterize(int* input, int heigth, int width) {
    int kn = 0, km = 0;
    int A = 0, B = 0, C = 0;
    int cur = 1;

    for (size_t i = 0; i < heigth; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {

            kn = j - 1;
            if (kn < 0)
            {
                kn = 0;
                B = 0;
            }
            else
            {
                B = input[i * width + kn];
            }

            km = i - 1;
            if (km < 0)
            {
                km = 0;
                C = 0;
            }
            else
            {
                C = input[km * width + j];
            }

            A = input[i * width + j];
            if (A == 0) continue;
            else
                if (B == 0 && C == 0)
                {
                    cur = cur + 1;
                    input[i * width + j] = cur;
                }
                else
                    if (B != 0 && C == 0)
                    {
                        input[i * width + j] = B;
                    }
                    else
                        if (B == 0 && C != 0)
                        {
                            input[i * width + j] = C;
                        }
                        else
                            if (B != 0 && C != 0)
                            {
                                input[i * width + j] = B;

                                if (C != B)
                                {
                                    int* ptr = (int*)input;
                                    size_t i1 = 0;
                                    while (&ptr[i1] <= &input[i * width + j])
                                    {
                                        if (ptr[i1] == C)
                                            ptr[i1] = B;
                                        ++i1;
                                    }
                                }
                            }
        }
    }
}

int FindMaxSquareObj(int* input, int heigth, int width) {
    std::map<int, int> objects;

    for (size_t i = 0; i < heigth; ++i)
        for (size_t j = 0; j < width; ++j)
        {
            if (input[i * width + j] == 0) continue;
            objects[input[i * width + j]]++;
        }

    int max = std::numeric_limits<int>::min();
    int max_obj = 0;

    for (auto& obj : objects)
        if (obj.second >= max) 
        { 
            max_obj = obj.first;
            max = obj.second; 
        }
    
    for (auto& obj : objects)
        std::cout << obj.first << " " << obj.second << std::endl;

    return max_obj;
}

int main(int argc, char *argv[]) {

    const int M = 13;
    const int N = 11;

    int a[M * N] = {
    1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
    0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    for (size_t i = 0; i < M; ++i)
    {
        for (size_t j = 0; j < N; ++j)
            std::cout << a[i * N + j] << " ";

        std::cout << std::endl;
    }

    
    Clusterize(a, M, N);


    std::cout << std::endl;

    for (size_t i = 0; i < M; ++i)
    {
        for (size_t j = 0; j < N; ++j)
            std::cout << a[i * N + j] << " ";

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout<<"max = "<<FindMaxSquareObj(a, M, N);
        
    std::cin.get();
	return 0;
}