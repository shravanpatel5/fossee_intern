// Shravan R. Patel
// IIT Mandi
// 2nd year CSE
// gmail : shravanpatel5@gmail.com

// Here, I am finding mimimum of negative of objective function that is maximum of objective function 

// problem.mps must contains negative of objective function
// For the given example, problem.mps file must contain -20x0-40x1-20x2-15x3-30x4  

// I am confused about how the problem should be described in the problem.mps file. Please Update the MPS file if it is wronge.

#include "CbcModel.hpp"						// To solve problem
#include "OsiClpSolverInterface.hpp"                  		// To take problem statement as input
int main (int argc, const char *argv[])
{
	double ans;
  	OsiClpSolverInterface solver; 				       
  	int errors = solver.readMps("problem.mps","");          // read the MPS file which contain negative of objective function
  	assert(errors==0);   					// assert that it is a clean model
  	CbcModel model(solver);			            	// Pass the solver having the problem to be solved to CbcModel 
	
	// Find the minimum of the negative of the objective function = maximum of objective function  	
	model.branchAndBound(); 			        
  	int nc = model.solver()->getNumCols();
  	const double * sol = model.bestSolution();		// assign best solution to sol pointer
  	for (int i=0;i<nc;i++) 
	{
    		ans=sol[i]; 
      		printf("x%d = %g\n",i,ans);
   	}
  	return 0;
}    


// Reference : http://www.coin-or.org/Cbc/cbcuserguide.html 
