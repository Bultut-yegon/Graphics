#include <stdio.h>

// Function to check if a point is inside the clip window
int isInside(int x, int y, int xmin, int ymin, int xmax, int ymax) {
  return (x >= xmin && x <= xmax && y >= ymin && y <= ymax);
}

// Function to clip a line using Liang Barsky Algorithm
void clipLine(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
  // Initialize parameters
  float tmin = 0.0f, tmax = 1.0f;
  float dx = x2 - x1;
  float dy = y2 - y1;

  // Check for each edge of the clipping window
  for (int edge = 0; edge < 4; edge++) {
    float p, q;
    // Calculate p and q values depending on the edge
    switch (edge) {
      case 0: // Left edge
        p = -dx; q = x1 - xmin;
        break;
      case 1: // Right edge
        p = dx; q = xmax - x1;
        break;
      case 2: // Bottom edge
        p = -dy; q = y1 - ymin;
        break;
      case 3: // Top edge
        p = dy; q = ymax - y1;
        break;
    }

    // Check if parallel to the edge
    if (p == 0) {
      if (q <= 0) {
        return; // Line is completely outside
      }
    } else {
      // Calculate t values for intersection with edge
      float t = q / p;
      if (p < 0) { // Entering edge
        tmin = tmax > t ? tmax : t;
      } else { // Exiting edge
        tmax = tmin < t ? tmin : t;
      }
    }

    // Check if line is completely outside
    if (tmax < tmin) {
      return; // Line is completely outside
    }
  }

  // Clip the line using tmin and tmax
  if (tmin > 0) {
    x1 += tmin * dx;
    y1 += tmin * dy;
  }
  if (tmax < 1) {
    x2 += tmax * dx;
    y2 += tmax * dy;
  }

  // Check if clipped line is inside the window
  if (isInside(x1, y1, xmin, ymin, xmax, ymax) && isInside(x2, y2, xmin, ymin, xmax, ymax)) {
    printf("Clipped line: (%d, %d) - (%d, %d)\n", x1, y1, x2, y2);
  }
}

int main() {
  // Define the clip window
  int xmin = 100, ymin = 100, xmax = 400, ymax = 400;

  // Define the line to be clipped
  int x1 = 50, y1 = 50, x2 = 450, y2 = 450;

  clipLine(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

  return 0;
}
