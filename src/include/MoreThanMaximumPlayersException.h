#include <exception>
#include <string>

class MoreThanMaximumPlayersException : std::exception
{
  private:
    std::string msg;

  public:
    explicit MoreThanMaximumPlayersException(const std::string &msg_) : msg(msg_)
    {
    }
    const char *what() const noexcept override
    {
        return msg.c_str();
    }
};