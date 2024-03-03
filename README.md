# CS-210-Portfolio

Cody VanGosen CS-210 03/02/2024

This is a repository of my project files and final submission for my final portfolio for the CS-210 Class at SNHU.

Summarize the project and what problem it was solving.

  This program was created to meet the function requirements of the ficitonal Airgead Banking company. The program seeks to provide an easy-to-use interface that presents the user with their account balances.
  This balance is calculated from the initial user input prompting for an initial investment amount, a monthly deposit, the annual interest (in %), & the number of years. Following this user prompt for their
  desired information they are presetned with a display informing them of the time in years, the year end balance, and the yearly earned interest. In addition, this interface will also show these same values
  with or without any further additional monthly deposits. This allows for the user to test theoretical desposits and investment amounts while seeing their ROI (the interest gained) and overall account balance
  year after year.

What did you do particularly well?

  I feel my design of the user interface was done particularly well in accordance with the provided template and rubric documentation. My program ran quickly and without error while maintaining data integrity
  through proper calculations, data maniupulation, and variable storage/update. The program was object-oriented and made use of a minimal main function with the majority of the program calculations and definitions
  occurring outside of the main function. This allowed for the main function to better serve as a call on the previously-defined functions instead.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

  I would like to expand on the error correction and detection. This would be best achieved by validating user-input and more carefully explaining the desired and accepted values for user input
that the program initially prompts for. In addition, I would like to implement garbage collection and furthermore implement some more memory-efficient practices to keep the program as lightweight as possible.
The other major change to implement would be to make better use of private and public function and data members throughout the program. This would help to better protect user and company data from malicious or
erroroneus issues.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  Initially I noticed I had made simple logic and clerical errors with the calculation portions of my program. This led to undesired or unexpected results for the output values of the program.
Through some intial debugging and further inspection I quickly realized I was forgetting to use the interest rate as a percentage. This key mistake and following correction led me to updating
the prompt for user information to include a percent symbol as well as implementing some error correction and input validation within the program. As alawys Stack Overflow is my go-to resource
whenever I am stumped on a programming issue after attempting to debug myself. Often-times seeing a different approach or how others might have faced similar issues can strike a new idea to 
tackle the problem at hand.

What skills from this project will be particularly transferable to other projects or course work?

  The user interfaces in particular seem to be extremely vauable skills to apply towards other projects or course work. Having a user-friendly display of information should always be a top priority.
In addition, validating user input and having catch statments for common errors are great industy-standard pracitce to implement in nearly all of my programming work going forward.

How did you make this program maintainable, readable, and adaptable?

The main way this program is readable and maintainable is through the use of in-depth in-line comments so that others can more quickly decypher how individual aspects of the program are attempting
to fulfill a purpose or solve a particular problem. In addition, using object-oriented programming can more easily allow for further upgrades through more function implmeentation. This is because the main function
is kept minimal and the other defined elements exist within their own functions. This can allow for the various parts of the function to co-exist independently from one another.
  
