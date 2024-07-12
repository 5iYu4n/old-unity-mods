#ifndef UTILS_H
#define UTILS_H

struct Vector2i
{
    int x, y;
    inline float Distance(Vector2i other)
    {
        Vector2i difference = Vector2i{this->x - other.x, this->y - other.y };
        return sqrt((difference.x * difference.x) + (difference.y * difference.y));
    }
    bool operator==(const Vector2i& other) const
    {
        return (this->x == other.x) && (this->y == other.y);
    }
    inline bool operator!=(const Vector2i& other)
    {
        return (this->x != other.x) || (this->y != other.y);
    }
    inline bool operator<(const Vector2i& other)
    {
        return (this->x < other.x) && (this->y < other.y);
    }
    inline bool operator>(const Vector2i& other)
    {
        return (this->x > other.x) && (this->y > other.y);
    }
    inline bool operator<=(const Vector2i& other)
    {
        return (this->x <= other.x) && (this->y <= other.y);
    }
    inline bool operator>=(const Vector2i& other)
    {
        return (this->x >= other.x) && (this->y >= other.y);
    }
};

#endif
