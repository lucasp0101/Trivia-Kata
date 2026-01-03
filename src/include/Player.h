#pragma once

#include <string> 

class Player
{
  public:
  Player(std::string name_) : name(name_), place(0), purse(0), inPenalty(false)
  {}

  std::string getName() const { return name; }

  int getPlace() const { return place; }
  void setPlace(int place_) { place = place_; }

  int getPurse() const { return purse; }
  void setPurse(int purse_) { purse = purse_; }

  bool getInPenalty() const { return inPenalty; }
  void setInPenalty(bool inPenalty_) { inPenalty = inPenalty_; }

  std::string toString() const {
    return name + " (place: " + std::to_string(place) + 
           ", purse: " + std::to_string(purse) + 
           ", inPenalty: " + (inPenalty ? "true" : "false") + ")";
  }

  private:
    std::string name;
    int place;
    int purse;
    bool inPenalty;
};