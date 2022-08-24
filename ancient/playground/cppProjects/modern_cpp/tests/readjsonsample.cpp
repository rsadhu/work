// rapidjson/example/simpledom/simpledom.cpp`
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/error/en.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace rapidjson;

int main(int argc, char *argv[])
{
  // 1. Parse a JSON string into DOM.
  const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
  std::string line, data;
  if (argc > 1)
  {
    std::ifstream filereader(argv[1], std::ios::binary);
    while (std::getline(filereader, line))
      data += line;
    json = data.c_str();
  }

  Document d;

  d.Parse(json);

  if (d.HasParseError())
  {
    fprintf(stderr, "\nError(offset %u): %s\n",
            (unsigned)d.GetErrorOffset(),
            GetParseError_En(d.GetParseError()));

    std::cout << " \nParsing Error :: " << d.GetParseError() << "  offset error : " << d.GetErrorOffset();
    return 1;
  }

  for (auto &m : d.GetObject())
  {
    std::string tagName = m.name.GetString();

    printf("Type of member %s \n", m.name.GetString());
    if (tagName == "map")
    {
      std::cout << " map : " << m.value.GetString();
    }
    else if (tagName == "description")
    {
      std::cout << " map : " << m.value.GetString();
    }
    else if (tagName == "objectPool")
    {
      for (auto &innerObjs : m.value.GetObject())
      {
        std::cout << innerObjs.name.GetString() << "\n";

        std::string innerTagName = innerObjs.name.GetString();

        if (innerTagName == "hostVehicle")
        {
          std::cout << "\nobjectId :" << innerObjs.value["objectId"].GetDouble();
          std::cout << "\nmodel:type :" << innerObjs.value["model"]["type"].GetString();
          std::cout << "\nx :" << innerObjs.value["x"].GetDouble();
          std::cout << "\ny :" << innerObjs.value["y"].GetDouble();
          std::cout << "\nheading :" << innerObjs.value["heading"].GetDouble();
          std::cout << "\nwidth: " << innerObjs.value["width"].GetDouble();
          std::cout << "\nlength: " << innerObjs.value["length"].GetDouble();
          std::cout << "\nvelocity: " << innerObjs.value["velocity"].GetDouble();
          std::cout << "\nlongitudinal_acceleration: " << innerObjs.value["longitudinal_acceleration"].GetDouble();
          std::cout << "\nlateral_acceleration :" << innerObjs.value["lateral_acceleration"].GetDouble();
        }
        else if (innerTagName == "vehicles")
        {
          for (int i = 0; i < innerObjs.value.Size(); i++)
          {
            std::cout << "\nobjectId :" << innerObjs.value[i]["objectId"].GetDouble();
            std::cout << "\nmodel:type :" << innerObjs.value[i]["model"]["type"].GetString();
            std::cout << "\nx :" << innerObjs.value[i]["x"].GetDouble();
            std::cout << "\ny :" << innerObjs.value[i]["y"].GetDouble();
            std::cout << "\nheading :" << innerObjs.value[i]["heading"].GetDouble();
            std::cout << "\nwidth: " << innerObjs.value[i]["width"].GetDouble();
            std::cout << "\nlength: " << innerObjs.value[i]["length"].GetDouble();
            std::cout << "\nvelocity: " << innerObjs.value[i]["velocity"].GetDouble();
            std::cout << "\nlongitudinal_acceleration: " << innerObjs.value[i]["longitudinal_acceleration"].GetDouble();
            std::cout << "\nlateral_acceleration :" << innerObjs.value[i]["lateral_acceleration"].GetDouble();
          }
        }
      }
    }
    else if (tagName == "fileVersion")
    {
      std::cout << " fileVersion::major" << m.value["major"].GetString();
      std::cout << " fileVersion::minor" << m.value["minor"].GetString();
    }
  }

  return 0;
}
