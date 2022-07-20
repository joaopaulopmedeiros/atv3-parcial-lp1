#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Map
{
public:
  Map();
  int width;
  int height;
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
  std::ofstream file;
  file.open(filePath, std::ifstream::out);
  if (file.is_open())
  {
    for (int i = 0; i < this->height; i++)
    {
      for (int j = 0; j < this->width; j++)
      {
        if (j == this->width - 1)
        {
          file << this->cells[i][j] << std::endl;
        }
        else
        {
          file << this->cells[i][j];
        }
      }
    }

    file.close();
  }
  else
  {
    std::cout << "[ERROR] Arquivo nao encontrado";
    exit(EXIT_FAILURE);
  }
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

  int height = 10;
  int width = 10;

  m.height = height;
  m.width = width;

  for (int i = 0; i < height; i++)
  {
    std::vector<int> cells;

    for (int j = 0; j < width; j++)
    {
      cells.push_back(1);
    }

    m.cells.push_back(cells);
  }

  return m;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "[ERROR] Por favor, informe o arquivo com o mapa desejado";
    exit(EXIT_FAILURE);
  }

  std::string filePath = argv[1];

  std::cout << "[INFO] Path do arquivo inputado: " << filePath << std::endl;

  MapSeeder seeder;

  Map map = seeder.seed();

  map.saveIntoFile(filePath);

  return 0;
}