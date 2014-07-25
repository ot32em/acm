#pragma once 

#include <iostream>
#include <array>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

namespace geo
{

struct Point 
{
    Point(int x_, int y_):x(x_), y(y_){}
    int x;
    int y;
};

struct Line
{
    Line(const Point& p1_, const Point& p2_):p1(p1_), p2(p2_){}
    Point p1;
    Point p2;
};


struct Canvas
{
    static const int ROW = 40;
    static const int COL = 40;
    typedef std::array<std::array<std::pair<char, char>, Canvas::COL>, Canvas::ROW> CanvasDataT;
    typedef std::pair<int, int> PointT; // x/y
    std::map<PointT, std::pair<char, char>> m_points;
    std::vector<Line> m_lines;

    Canvas() {}

    void display() const
    {
        CanvasData canvas_data;
        for(const auto& p: m_points)
        {
            auto& key = p.first;
            auto& value = p.second;

            // write point
            canvas_data.paint(key.first, key.second, value.first, value.second);

            // write text
            std::ostringstream ss;
            ss << "(" << key.first << "," << key.second << ")";
            std::cout << ss.str() << std::endl;
            canvas_data.paint(key.first + 1, key.second, ss.str());
        }

        for(const auto& line: m_lines)
        {
            // write point
            canvas_data.paint(line.p1.x, line.p1.y, 'O');
            canvas_data.paint(line.p2.x, line.p2.y, 'o');

            // write line
            canvas_data.paint(line.p1, line.p2);
        }
        canvas_data.render();
    }

    void add_point(int x, int y, char c='x', char c2=' ')
    {
        m_points.insert(std::make_pair(std::make_pair(x, y), std::make_pair(c, c2)));
    }
    void del_point(int x, int y)
    {
        m_points.erase(std::make_pair(x, y));
    }

    void add_line(int x, int y, int x2, int y2)
    {
        m_lines.push_back(Line(Point(x,y), Point(x2, y2)));
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
                        e_iter->first = '|';
                        e_iter->second = '|';
                    }
                    else if(row_iter == m_data.begin() ||
                            row_iter == m_data.begin() + m_data.size() - 1)
                    {
                        e_iter->first = '-';
                        e_iter->second = '-';
                    }
                    else
                    {
                        e_iter->first = ' ';
                        e_iter->second = ' ';
                    }
                }
            }
        }

        void paint(int x, int y, const std::string& s)
        {
            int i=0;
            bool half=false;
            char last_c = s[0];
            for(char c:s)
            {
                if(half)
                {
                    half = false;
                    i++;
                    paint(x+i, y, last_c, c);
                }
                else
                {
                    half = true;
                }
                last_c = c;
            }
            if(half)
            {
                paint(x+i+1, y, last_c);
            }
        }

        void paint(int x, int y, char c='x', char c2=' ')
        {
            if(y >= ROW || y < 0)
                return;
            if(x >= COL || x < 0)
                return ;
            m_data[y][x] = std::make_pair(c, c2);
        }

        void paint(const Point& p1, const Point& p2)
        {
            bool right = (p2.x>p1.x);
            int dx = p2.x - p1.x;
            int dy = p2.y - p1.y;
            double d = std::hypot(dx, dy);
            for(double i=0;i<=d;i++)
            {
                double t = i/d;
                int xt = p1.x + (p2.x-p1.x) * t;
                int yt = p1.y + (p2.y-p1.y) * t;
                paint(xt, yt, '.');
            }
            paint(p1.x, p1.y, '<', '>');
            paint(p2.x, p2.y, '(', ')');

        }
        void erase(int x, int y)
        {
            if( y >= ROW || y < 0)
                return;
            if( x >= COL || x < 0)
                return;
            m_data[y][x] = std::make_pair(' ', ' ');
        }
        
        void render(std::ostream& out = std::cout) const
        {
            for(auto iter = m_data.rbegin(); iter != m_data.rend(); iter++)
            {
                for(auto p: *iter) { out << p.first << p.second; }
                out << std::endl;
            }
        }
    };

};

};
