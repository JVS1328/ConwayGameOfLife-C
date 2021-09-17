/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/2015 and modified to use an infinite loop
/// and have different Rule functions.
///
/// @author: John Skorcik
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own. You should make the formatting consistent.
/// </li>
/// <li>  documentation: documentation is non-existent except for this block.
/// </li>
/// </ol>
///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void header(void) {
      printf("\n\t..Welcome to the Game of life..\n");
}


/**
  Helper function to compute the number of neighbors that exist around an organism.
  @param size - the size of the grid/matrix
  @param life - the matrix itself (grid)
  @return the number of neighbors
*/
int computeNeighbors(int size, int row, int col, char life[][size]) {

      int neighbors = 0;
      int tcol = col; ///hold orig. col value
      int trow = row; ///hold orig. row value
      
      
      if ((col - 1) < 0)
        col = size;
      if(life[row][col - 1] == '*')
        neighbors++;
        
      col = tcol;
      
      if ((col + 1) == size)
        col = -1;
      if(life[row][col + 1] == '*')
        neighbors++;
        
      col = tcol;
        
      if ((row - 1) < 0)
        row = size;
      if(life[row - 1][col] == '*')
        neighbors++;
        
      row = trow;
      
      if ((row + 1) == size)
        row = -1;
      if(life[row + 1][col] == '*')
        neighbors++;
        
      row = trow;
        
      if ((row - 1) < 0)
        row = size;
      if ((col - 1) < 0)
        col = size;
      if(life[row - 1][col - 1] == '*')
        neighbors++;
      
      row = trow;
      col = tcol;
      
      if ((row + 1) == size)
        row = -1; 
      if ((col + 1) == size)
        col = -1;
      if(life[row + 1][col + 1] == '*')
        neighbors++;
        
      row = trow;
      col = tcol;
        
      if ((row - 1) < 0)
        row = size;
      if ((col + 1) == size)
        col = -1;
      if(life[row - 1][col + 1] == '*')
        neighbors++;
      
      row = trow;
      col = tcol;
      
      if ((row + 1) == size)
        row = -1;
      if ((col - 1) < 0 )
        col = size;
      if(life[row + 1][col - 1] == '*')
        neighbors++;
      
      return neighbors;

}


/**
  Central Rules Function that run's conway's game. Handles Death, Birth, and Survivability..
  @param size - the size of the grid/matrix
  @param life - the matrix itself (grid)
*/
void conwayRules(int size, char life[][size]){
      int row, col;
      int neighbors = 0;
      char lifeCopy[size][size];
      memcpy(lifeCopy, life, sizeof(lifeCopy)); ///copy the array over so that checks are made against orig.
      for(row = 0; row<size; row++) {
         for(col = 0; col<size; col++) {
         
           neighbors = computeNeighbors(size, row, col, lifeCopy);
           
           
           if(lifeCopy[row][col] == ' ' && neighbors == 3)
             life[row][col] = '*';
           else if (lifeCopy[row][col] == '*' && (neighbors == 2 || neighbors == 3))
             life[row][col] = '*';
           else
             life[row][col] = ' ';
             
         }
      }
      return;
}


int main(void) {

      int orgs; //orgs = organisms
   
      int i, row, col;
      int count = 0;
      int size = 20;
      char life[size][size];


      header();

      printf("\nPlease enter the initial number of organisms: ");
      scanf("%i", &orgs);

      srand( 31 );
      
      for(i = 0; i<orgs; i++) { /// Initialize the grid
          row = rand();
          row %= size;
          col = rand();
          col %= size;
          
          /// Added check so it doesn't override existing organisims.
          /// If organism exists on pos, skip - Else, add organism.
          if (life[row][col] == '*'){
            i -= 1;
            continue;
          }
          else
            life[row][col] = '*'; /// Fix 2C: == is Comparison, not assignment (=)
      }

      for(row = 0; row<size; row++) {
          for(col = 0; col<size; col++) {
              if(life[row][col] != '*')
                life[row][col] = ' '; /// Fix 2D: == is Comparison, not assignment (=)
          }
      }

      ///Fix 4: End output after 100 generations
      while ( count <= 100 ) {
          if (count != 0) /// Leave Generation 0 alone so i prints all nice
            conwayRules(size, life);
          ///int endOrgs = 0; //Setting up orgs tracker for the CURRENT number of ALIVE organisms.
          for(row = 0; row<size; row++) {
              for(col = 0; col<size; col++) {
                  printf("%c", life[row][col]); //Fix 1B - Output stated String, supposed to be char.
                  ///if (life[row][col] == '*')
                    ///endOrgs += 1;

              }
              puts(" ");
          }
          printf("\ngeneration: %d\n", count);
          ///printf("\nalive organisms: %d\n", endOrgs);
          count++;
      }

      return 0;
}

