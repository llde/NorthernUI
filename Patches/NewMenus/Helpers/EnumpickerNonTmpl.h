#pragma once
#include "ReverseEngineered/UI/Menu.h"
#include "ReverseEngineered/UI/Tile.h"

#include <initializer_list>
#include <string>
#include <vector>

namespace XXNMenuHelpers {
   struct EnumpickerUInt {
      EnumpickerUInt() {};
      EnumpickerUInt(bool sorted, std::initializer_list<UInt32> v) {
         this->sorted = sorted;
         this->values = v;
      };
      EnumpickerUInt(std::initializer_list<UInt32> v) { this->values = v; };

      UInt32    index = 0;
      RE::Tile* tileLeft = nullptr;
      RE::Tile* tileRight = nullptr;
      RE::Tile* tileValue = nullptr;
      std::vector<UInt32> values;
      bool requiresRestart = false;
      bool sorted = false; // note: only applied when Set adds an entry into the list; just sort your initializer lists by hand, friendo

      UInt32 Get() const;
      SInt32 IndexOf(const UInt32) const;
      bool HandleClick(RE::Tile* tile); // returns true if event handled; false if event not relevant
      void Render() const;
      void Set(const UInt32 value, bool addIfMissing = true);
      void Sort(); // WARNING: Doesn't update this->index !
      void Stringify(std::string& out, UInt32 index) const;
   };
   //
   struct EnumpickerStr {
      EnumpickerStr() {};
      EnumpickerStr(bool sorted) {
         this->sorted = sorted;
      };

      UInt32    index = 0;
      RE::Tile* tileLeft = nullptr;
      RE::Tile* tileRight = nullptr;
      RE::Tile* tileValue = nullptr;
      std::vector<std::string> values;
      bool requiresRestart = false;
      bool sorted = false; // note: only applied when Set adds an entry into the list; just sort your initializer lists by hand, friendo

      void AddValue(const char*);
      std::string Get() const;
      SInt32 IndexOf(const std::string&) const;
      bool HandleClick(RE::Tile* tile); // returns true if event handled; false if event not relevant
      void Render() const;
      void Set(const std::string& value, bool addIfMissing = true);
      void SetByIndex(UInt32); // if the index is out-of-bounds, no changes are made; default index for a new enumpicker is 0
      void Sort(); // WARNING: Doesn't update this->index !
      void Stringify(std::string& out, UInt32 index) const;
   };
};