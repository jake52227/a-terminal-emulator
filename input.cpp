#include "input.hpp"

Input::Input(int history_capacity)
{
    this->history_capacity = history_capacity;
    this->history = std::deque<std::string>();
}

void Input::store_current_to_history()
{
    std::string s(input_buffer.begin(), input_buffer.end());
    if (input_buffer.size() == 0)
        return;
    input_buffer.clear();
    history_size += 1;
    if (history_size == history_capacity)
    {
        history.pop_back();
        history_size -= 1;
    }
    history.push_front(s);
    history_index = 0;
}

std::string Input::get_previous()
{
    if (history_size == 0)
    {
        return "";
    }
    if (history_index == history_size)
    {
        return history.at(history_index - 1);
    }
    return history.at(history_index++);
}

std::string Input::get_next()
{
    if (history_index == 0)
    {
        return history.at(history_index);
    }
    return history.at(--history_index);
}

void Input::add_one(char c)
{
    input_buffer.push_back(c);
}

void Input::remove_one()
{
    if (input_buffer.size() > 0) {
        input_buffer.pop_back();
    }
}

std::string Input::get_input_buffer()
{
    return std::string(input_buffer.begin(), input_buffer.end());
}