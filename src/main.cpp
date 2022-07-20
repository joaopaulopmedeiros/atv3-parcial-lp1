#include <iostream>
#include <vector>
#include <string>

class Map
{
public:
  Map();
  std::vector<std::vector<int>> cells;
  void saveIntoFile(std::string filePath);
  Map getFromFile(std::string filePath);
};

Map::Map()
{
  std::vector<std::vector<int>> cells = std::vector<std::vector<int>>();
}

void Map::saveIntoFile(std::string filePath)
{
}

Map getFromFile(std::string filePath)
{
  Map map;
  return map;
};

class MapSeeder
{
public:
  Map seed();
};

Map MapSeeder::seed()
{
  Map m;

  for (size_t i = 0; i < 10; i++)
  {
    for (size_t j = 0; j < 10; j++)
    {
      m.cells[i].push_back(i);
    }
  }

  return m;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Por favor, informe o arquivo com o mapa desejado";
    exit(EXIT_FAILURE);
  }

  MapSeeder seeder;

  Map map = seeder.seed();

  map.saveIntoFile(argv[1]);

  return 0;
}