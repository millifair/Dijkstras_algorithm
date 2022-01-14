#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
//матрица смежности
//алгоритм Дэйкстры
typedef int32_t vertex_t;
    class Graph2 {
    public:
        int edges_number;
        int veretexes_number;
        std::vector<std::pair<int, bool>> vertex;
        Graph2() :veretexes_number(0), edges_number(0) {};
        std::vector<std::vector<std::pair<int, int>>> matrix;

        void input() {
            std::cout << "введите количество вершин" << std::endl;
            std::cin >> veretexes_number;
            matrix.resize(veretexes_number);
            for (auto& line : matrix) {
                line.resize(veretexes_number,std::make_pair(0,0));
            }
            std::cout << "введите количество графов" << std::endl;
            std::cin >> edges_number;
            for (vertex_t i = 0;i < edges_number;++i) {
                vertex_t a, b,length;
                std::cout << "введите пары" << std::endl;
                std::cin >> a >> b;
                std::cout << "введите расстояние между этими вершинами" << std::endl;
                std::cin >> length;
                matrix[a] [b]= std::make_pair(1, length);
                matrix[b][a] = std::make_pair(1, length);
             
            }
        }
        void print_matrix() const {
            std::cout << "veretexes_number" << veretexes_number << std::endl;
            for (vertex_t a = 0;a < veretexes_number;++a) {
                for (vertex_t b = 0;b < veretexes_number;++b) {
                    std::cout << matrix[a][b].first <<" ("<< matrix[a][b].second << ")  ";
                }
                std::cout << std::endl;
            }
        }
        void print_length() const {
            std::cout << "длина до крайней вершины равна:  " << std::endl;
            std::cout << vertex.back().first<<std::endl;
        }
        void find_best_length() {
            std::cout << "найти оптимальное расстояние до крайней вершины " << std::endl;
            int a = 0;
            int c;
            int counter=0;
            bool flag = true;
            vertex_t min_vert = INT_MAX;
            vertex.resize(veretexes_number, std::make_pair(INT_MAX, 0));
            vertex.at(0).first = 0;
            while (flag) {
                for (vertex_t b = 0;b < veretexes_number;++b) {
                    vertex.at(a).second = 1;
                    if ((matrix[a][b].first == 1) && ((matrix[a][b].second + vertex[a].first) < vertex[b].first)) {
                        vertex[b].first = (matrix[a][b].second + vertex[a].first);
                        std::cout << "вершина" << std::endl;
                        std::cout << vertex[b].first << std::endl;
                    }
                    if ((vertex[b].first < min_vert) && (vertex[b].second==0)) {
                        c = b;
                        min_vert = vertex[b].first;
                    }
                }
                min_vert = INT_MAX;
                a = c;
                for (auto & element : vertex) {
                    if (element.second == 0) {
                        counter++;
                    }
                }
                if (counter == 0) {
                    flag = false;
                }
                counter = 0;
            }
        }
    };
    int main()
    {
        setlocale(LC_ALL, "Russian");
        Graph2 g1;
        g1.input();
        g1.print_matrix();
        g1.find_best_length();
        g1.print_length();

    }

