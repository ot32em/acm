#include <iostream>
#include <array>
#include "geo.h"
#include <sstream>
#include <vector>
#include <map>


struct Canvas
{
    static const int ROW = 23;
    static const int COL = 80;
    typedef std::array<std::array<char, Canvas::COL>, Canvas::ROW> CanvasDataT;
    typedef std::pair<int, int> PointT; // x/y
    std::map<PointT, char> m_points;

    Canvas() {}

    void display() const
    {
        CanvasData canvas_data;
        for(const auto& p: m_points)
        {
            auto& key = p.first;
            auto& value = p.second;

            // write point
            canvas_data.paint(key.first, key.second, value);

            // write text
            std::ostringstream ss;
            ss << "(" << key.first << "," << key.second << ")";
            std::cout << ss.str() << std::endl;
            canvas_data.paint(key.first + 1, key.second, ss.str());
        }
        canvas_data.render();
    }

    void add_point(int x, int y, char c='x')
    {
        m_points.insert(std::make_pair(std::make_pair(x, y), c));
    }
    void del_point(int x, int y)
    {
        m_points.erase(std::make_pair(x, y));
    }


    class CanvasData
    {
        CanvasDataT m_data;
    public:

        CanvasData()
        {
            for(auto row_iter = m_data.begin(); row_iter != m_data.end(); row_iter++)
            {
                for(auto e_iter = row_iter->begin();
                         e_iter != row_iter->end();
                         e_iter++)
                {
                    if(e_iter == row_iter->begin() ||
                       e_iter == row_iter->begin() + row_iter->size() - 1)
                    {
                        *e_iter = '|';
                    }
                    else if(row_iter == m_data.begin() ||
                            row_iter == m_data.begin() + m_data.size() - 1)
                    {
                        *e_iter = '-';
                    }
                    else
                    {
                        *e_iter = ' ';
                    }
                }
            }
        }

        void paint(int x, int y, const std::string& s)
        {
            int i=0;
            for(char c:s)
                paint(x + (i++), y, c);
        }

        void paint(int x, int y, char c='x')
        {
            if(y >= ROW || y < 0)
                return;
            if(x >= COL || x < 0)
                return ;
            m_data[y][x] = c;
        }
        void erase(int x, int y)
        {
            if( y >= ROW || y < 0)
                return;
            if( x >= COL || x < 0)
                return;
            m_data[y][x] = ' ';
        }
        
        void render(std::ostream& out = std::cout) const
        {
            for(auto iter = m_data.rbegin(); iter != m_data.rend(); iter++)
            {
                for(auto p: *iter) { out << p; }
                out << std::endl;
            }
        }
    };

};


int main(int argc, char** argv)
{
    Canvas canvas;
    canvas.add_point(3,3);
    canvas.display();


};
