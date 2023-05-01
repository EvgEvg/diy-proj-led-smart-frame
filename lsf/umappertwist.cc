#include <getopt.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <vector>
#include <string>

class UArrangementTwistMapper {
public:
  UArrangementTwistMapper() {}

  virtual void MapVisibleToMatrix(int matrix_width, int matrix_height,
                                  int x, int y,
                                  int *matrix_x, int *matrix_y) const {
    const int panel_height = matrix_height / parallel_;
    const int visible_width = (matrix_width / 64) * 32;
    const int slab_height = 2 * panel_height;   // one folded u-shape
    const int base_y = (y / slab_height) * panel_height;
    y %= slab_height;
    if (y < panel_height) {
      x += matrix_width / 2;
    } else {
      x = visible_width - x - 1;
      y = slab_height - y - 1;
    }
    *matrix_x = x;
    *matrix_y = base_y + y;

    fprintf(stderr, "X %d Y %d", matrix_x, matrix_y);
  }

}


// Here we are going to test the UArrangementTwistMapper class.
int main()
{
    // Init
    int matrixW = 128;
    int matrixH = 128;
    int resultX = 0;
    int resultY = 0;

    UArrangementTwistMapper *UTwist = new UArrangementTwistMapper();

    UTwist::MapVisibleToMatrix(128, 128, 0, 0, resultX, resultY);

    // clean up.
    delete UTwist;

    return 0;
}
