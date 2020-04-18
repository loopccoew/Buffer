# Buffer
The buffer project series repository
# A Comparative Performance Analysis of Popular Algorithms in Languages you've studied

# Abstract

There are many programming languages existent in this world, each of them with its own pros and cons. C, CPP, Python are very extensively used for different purposes. While C and CPP have been used since a long time and are still in demand, Python has become popular in the recent times comparatively. This **research project focuses on the comparative analysis of these languages with other different aspects like processors, sorting techniques (Sorting refers to the arrangement of data in a particular order using a particular logic.) and amount of data given as input.**
# Literature Review
- ## **_INTRODUCTION:_**

**What is an algorithm?**

In mathematics and computer science, an **algorithm** is a finite sequence of well-defined, computer-implementable instructions, typically to solve a class of problems or to perform a computation. An algorithm can be expressed within a finite amount of space and time, and in a well-defined formal language for calculating a function. Starting from an initial state and initial input (perhaps empty), the instructions describe a computation that, when executed , proceeds through a finite number of well-defined successive states, eventually producing "output"  and terminating at a final ending state.

Some algorithms are more efficient than others, in that less time or memory is required to execute them. The analysis of algorithms studies time and memory requirements of algorithms and the way those requirements depend on the number of items being processed.

**What is sorting?**

A sorting algorithm is a method for reorganizing a large number of items into a specific order, Sorting algorithms take lists of items as input data, perform specific operations on those lists and deliver ordered arrays as output.
Various sorting algorithms used in this process are:

	  - Bubble sort
	   
	  - Selection Sort
	   
	  - Insertion Sort
	   
	  - Merge Sort
	   
	  - Radix Sort

### **A.** **Bubble sort**,
sometimes referred to as **sinking sort**, is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps "Swap (computer science)") them if they are in the wrong order. The algorithm, which is a comparison sort, is named for the way smaller or larger elements "bubble" to the top of the list. This simple algorithm performs poorly in real world use and is used primarily as an educational tool.

 ***1. Algorithm:***
    
    	1. for  i = 0 to (n-1)
    
    		1.1. for  j = 0 to (n-i-1)
    
    			1.1.1. if  (arr[j] > arr[j+1])
    
    				1.1.1.1. swap(arr[j], arr[j+1])
    
    			1.1.2. end if
    
    		1.2. end inner for
    
    	2. end outer for
    
 ***2. Example:***
 

![enter image description here](http://www.equestionanswers.com/c/images/bubble-sort-step1-iteration-stages.png)
	
***3. Analysis:*** Bubble sort is data sensitive. The number of iterations required may be between 1 and (N-1). The best case for bubble sort is when only one iteration is required. The number of comparisons required is (N-1). The worst case arises when the given array is sorted in reverse order.

		Best Case = O (n)

		Average Case = O (n^2)

		Worst Case= O (n^2)



### **B.** **Selection sort**
this algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array. This process continues moving unsorted array boundary by one element to the right.

***1) Algorithm:***

		1. for  int  i = 0 to (n-1)

		2. Find the minimum element in unsorted array

			2.1. int  min_idx = i;

			2.2. for  int  j = (i+1) to n

				2.2.1. if  (arr[j] < arr[min_idx])

				2.2.1.1. min_idx = j;

		3. Swap the found minimum element with the first element

		4. End outer for


***2) Example:***

![enter image description here](http://brianredd.com/wp-content/uploads/2015/09/SelectionSortExample_v5.png)


***3) Analysis:*** Selecting the smallest element requires scanning all n elements, so this takes n − 1 comparisons and then swapping or interchanging it into the first position. Finding the next lowest element requires scanning the remaining (n − 1) elements and so on, for

(n − 1) + (n − 2) + ... + 2 + 1 = n (n − 1) / 2= O(n2)

	Best Case = O(n^2)

	Average Case= O(n^2)

	Worst Case= O(n^2)

### **C.** **Insertion Sort**
this algorithm works just like its name suggests - it inserts each item into its proper place in the final list. In Insertion sort, the first iteration starts with comparison of 1st element with 0th element. In the second iteration the element is compared with 0th and 1st element. In general in every iteration an element is compared with all elements. If at same point it is found the element can be inserted at a position then space is created for it by shifting the other element one position right and inserting the element at the suitable position. This procedure is repeated for all the elements in the array.

***1) Algorithm:***

		Step 1 − If it is the first element, it is already sorted. return 1;

		Step 2 − Pick next element

		Step 3 − Compare with all elements in the sorted sub-list

		Step 4 − Shift all the elements in the sorted sub-list that is greater than the value to be sorted

		Step 5 − Insert the value
	
		Step 6 − Repeat until list is sorted

***2) Example:***

![enter image description here](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/insertionsort.png)
***3) Analysis***

The implementation of insertion Sort shows that there are (n−1) passes to sort n . The iteration starts at position 1 and moves through position (n−1), as these are the elements that need to be inserted back into the sorted sublists. The maximum number of comparisons for an insertion sort is (n−1) .Total numbers of comparisons are:

(n − 1) + (n − 2) + ... + 2 + 1 = n (n − 1) / 2=O(n2)

	Best Case = O(n^2)

	Average Case= O(n^2)

	Worst Case= O (n^2)




### **D.** **Merge Sort:**

This sorting method is an example of the Divide-And-Conquer paradigm i.e. it breaks the data into two halves and then sorts the two half data sets recursively, and finally merges them to obtain the complete sorted list. Conceptually, a merge sort works as follows

- Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).

- Repeatedly merge sublists to produce new sublists until there is only 1 sublist remaining. This will be the sorted list.

***1) Algorithm:***

		Step 1 − if it is only one element in the list it is already sorted, return.

		Step 2 − divide the list recursively into two halves until it can no more be divided.

		Step 3 − merge the smaller lists into new list in sorted order.

***2) Example:***
					![enter image description here](https://www.geeksforgeeks.org/wp-content/uploads/Merge-Sort-Tutorial.png)

***3) Analysis:*** In order to analyze the Merge Sort function, we need to consider the two distinct processes that make up its implementation. First, the list is split into halves. We divide a list in half logn times where n is the length of the list. The second process is the merge. Each item in the list will eventually be processed and placed on the sorted list. So the merge operation which results in a list of size n requires n operations. The result of this analysis is that logn splits, each of which costs n for a total of n (log n) operations.

		Best Case = O (n logn)
		Average Case= O (n logn)
		Worst Case= O (n logn)

### **E.** **Radix Sort** 
sorts the numbers according to their digits. The comparisons are made among the digits of the number from LSB to MSB. The number of passes depends upon the length of the number with the most number of digits.

***1) Algorithm:***

		Step 1 : Find the largest number in ARR as LARGE

		Step 2 : [INITIALIZE] SET NOP = Number of digits in LARGE

		Step 3 : SET PASS =0

		Step 4 : Repeat Step 5 while PASS <= NOP-1

		Step 5 : SET I = 0 and INITIALIZE buckets

		Step 6 : Repeat Steps 7 to 9 while I<n-1< li=""></n-1<>

		Step 7 : SET DIGIT = digit at PASSth place in A [I]

		Step 8 : Add A[I] to the bucket numbered DIGIT

		Step 9 : INCREMENT bucket count for bucket  
		numbered DIGIT  
		[END OF LOOP]

		Step 10 : Collect the numbers in the bucket  
		[END OF LOOP]

		Step 11 : END

***2) Example:***

![enter image description here](http://scanftree.com/Data_Structure/radixpro.png)

***3) Analysis:***

Since radix sort is a non-comparative algorithm, it has advantages over comparative sorting algorithms.

	Best Case:O(n+k)

	Average Case:O(nk)

	Worst Case:(nk)



- ## **_RELATED WORK:_**

Implementing a sorting application in C, C++ and Python for comparative analysis would be a major undertaking. To date, no one appears to have attempted such a study. There have been research topics that compare different sorts in the same language, on a single operating system. There have been several published studies comparing the performance of Java versus C++, or compare Java to both C and C++ (Bernardin et. al.), or comparing Java and C (Bull, et. al.). Prechelt presents a comparison of 40 different implementations (24 written in Java, 11 in C++, and 5 in C) of the same program written by 38 different programmers.

We attempt to study five sorting algorithms in three different languages, over four batches of large number of inputs. All these sorting algorithms behave differently in different languages, when compiled and run for varying randomly generated inputs. By providing randomly generated numbers, we consider a wide operation where analysis can be done for all ranges of numbers. These randomly generated numbers are stored in an array and provided as input. Number of elements as input goes from 10000, 50000,100000,500000.  A randomly generated array, of say 10000 numbers, is passed as input for all the five sorting methods, one by one and the execution time for these 10000 numbers in every individual sort is noted.

Another point taken into account is processors. Every processor has different functioning due to which the time required to execute processes vary. Intel makes a lot of processors. There are i3, i5, i7 and i9 CPUs. The higher the number, the more powerful is the processor. Different processor families have different levels of efficiency. We run all these codes on four different machines with different processors, which eventually affect the execution time.

Thus, to sum up or project deals with running five sorting algorithms in three different widely used languages: C, C++ and Python, on four different machines with different processors of Intel i3, i5 and i7, and analyzing the time it takes to execute these codes.

# Research Methodology

The three languages that we chose for this project are  **C, C++ and Python.**

These are the most popular languages and used extensively in the industries which is why we chose them so that we could judge how their performance is with respect to each other.

The five sorting techniques that we chose for this project are **Bubble, Selection, Insertion, Merge and Radix Sort.**

All the research was done on *four different combinations of processors* mentioned in the sheet since factors like these change the readings by 5-10% which is quite small considering our readings, which in turn are already small.

The operating system that we chose for this research project is *Windows* since it is easily available and most widely used.

Talking about the compilers we were using for this project we tried to do it on Online compilers so that everybody would work on the same platform but the disadvantage of this technique is that network delay and speed of the internet used comes into the picture whose stabilization seemed difficult and would add up to the error in the result. So we ruled that technique out.

Same compiler of the same version for each language  across all machines were used to be on the same platform.

With respect to data, the slots of data chosen are **10,000 , 50,000 , 1,00,000 , 5,00,000 randomly generated numbers** which are common for the all the sorts across all the languages.

We first generated these positive random numbers once for each slot which are present in the .txt files and then used the same for our codes as in when required. By doing this we ensured the readings are taken for the same data to erase any kind of ambiguity. Since when you compare anything you need a common platform to draw conclusions.

The codes that we used for calculating the time execution for each slot of numbers and each language has been uploaded. Also the sheet wherein we compare the time readings for everything and the generate ratios among the languages and their respective graphs has been uploaded.


A single code was generated in each language for all the sorts with the aim to cut short any kind of errors generated.

All the language codes were run on all combinations of processors.

It was realized that in the later slots since the number of numbers increased manifold there was a slight variation in the readings being taken, so an average of five readings was taken for the last slot.

After taking the reading of execution timings for the above mentioned methodology, Comparison ratios were generated with all the permutations and graphs were plotted of the readings taken to make analysis simpler.
# Analysis

# Compiled VS Interpreted Languages Performance Analysis




## Compiled Languages

Compiled languages are converted directly into machine code that the processor can execute. As a result, they tend to be faster and more efficient to execute than interpreted languages. They also give the developer more control over hardware aspects, like memory management and CPU usage.

Compiled languages need a “build” step - they need to be manually compiled first. You need to “rebuild” the program every time you need to make a change.

Examples of pure compiled languages are C, C++, Erlang, Haskell, Rust, and Go.

##  Interpreted Languages

Interpreters will run through a program line by line and execute each command.

Interpreted languages were once known to be significantly slower than compiled languages. But, with the development of just-in-time compilation, that gap is shrinking.

Examples of common interpreted languages are Java, PHP, Ruby, Python, and JavaScript.

##  Advantages and Disadvantages

### Advantages of Compiled Languages

Programs compiled into native code at compile time usually tend to be faster than those translated at run time, due to the overhead of the translation process.

### Disadvantages of Compiled Languages
The most notable disadvantages are :-
-   Additional time needed to complete the entire compilation step before testing, and
-   Platform dependence of the generated binary code.

### Advantages of Interpreted Languages

An Interpreted language gives implementations some additional flexibility over compiled implementations. Because interpreters execute the source program code themselves, the code itself is platform independent (Java’s byte code, for example). Other features include dynamic typing, and smaller executable program size.
### Disadvantages of Interpreted Languages
 The most notable disadvantage is less execution speed compared to compiled languages


# Comparative Performance Analysis of Different Languages ( C , C++,Python)

## C vs C ++

The _C++ vs C Comparison Ratio_ columns, with **performance degradation ratios as high as 2.667**, clearly depict the unacceptable performance of C++ versus C. This is because

C++ allows you to write abstractions that compile-down to equivalent C. This means that with some care, a **C++ program will be at least as fast as a C one**. ***The advantage C++ gives over C is that it enables us to also build reusable abstractions with templates, OOP and functional composition.***

C++ gives you the tools to encode your intentions in the type-system. This allows the compiler to generate optimal binaries from your code.

## Python vs C ++

**The _Python vs C++_ columns show performance degradation ratios as high as 404(avg).**

When it comes to Python vs C++, it is a dynamic language which reduces complexity when it comes to collaborating and optimizes programmer efficiency.  **C++ has the advantage of being a statically typed language. The performance crown goes to C++ for creating a more compact and faster runtime code.**

## C vs Python

**Python is 662(avg) times slower than C because it is an interpreted language.**  python code will be interpreted, instead of directly by the CPU.

_This makes all the difference in the world, regarding performance._

Python code almost always runs in a virtual machine.

Another name for a virtual machine is a “bytecode interpreter”.

**_Interpreted code is always slower than direct machine code, because it takes a lot more instructions in order to implement an interpreted instruction than to implement an actual machine instruction._**


# Comparative Performance Analysis of Different Processors ( i3,i5,i7)


Intel’s current core processors are divided into three ranges(**Core i3, Core i5 and Core i7**), with several models in each range.

| **PERSONAL COMPUTER**| Clock Speed Range(Several Models) |
|--|--|
|**INTEL CORE I3**  | 3.4GHz – 4.2GHz |
|**INTEL CORE I5** | 2.4GHz – 3.8GHz |
|**INTEL CORE I7** | 2.9GHz – 4.2GHz
 |
The clock speed (or clock rate) is stated in megahertz (MHz) or gigahertz (GHz) and refers to the speed at which the processor can execute instructions. The faster the clock, the more instructions the processor can complete per second.

_All else being equal,_ processors with faster clock speeds process data faster than those with slower clock speeds.

This may be interesting, **the slowest Core i3 chips runs at a faster speed than the base Core i5 and Core i7.**

**Core i3 processors don’t have Turbo Boost** **, but Core i5 and Core i7s do.** Turbo Boost dynamically increases the clock speed of Core i5 and i7 processors when more power is required. This means that the chip can draw less power, produce less heat and only boost when it needs to. For example, although a Core i3-7300 runs at 4GHz compared to 3.5GHz for the Core i5-7600, the Core i5 chip can boost up to 4.1GHz when required, so will end up being quicker. A processor can only Turbo Boost for a limited amount of time. It is a significant part of the reason why Core i5 and Core i7 processors outperform Core i3 models in single-core-optimized tasks, even though they have lower base clock speeds.

**That’s why, i7 processor takes the least time to execute the program while i3 processor takes more time to execute than i5 as it does not have a Turbo Boost like i5 and i7.**


# Result

In this research based project we have described our work on **comparative analysis of popular algorithms in C, C++ and Python.**
The algorithms that we chose, were **Bubble sort, Selection sort, Insertion sort , Merge sort and Radix sort.**
The result obtained from above analysis says that, Bubble Sort, Selection Sort and Insertion Sort are fairly straightforward, but they are relatively inefficient except for small sized arrays. Merge Sort and Radix Sort are more complicated, but also much faster for large sized arrays. Merge Sort is, on average, the fastest algorithm. Bubble Sort  algorithm is the slowest.
In addition to this ,we have also established the fact that **performance wise C++ is the fastest language when compared with C and Python.**
Although there are minor differences between C and C++, **C++ is preferred over C** as it **enables the user to build reusable abstractions with templates, OOP and functional composition.**
**Python being an Interpreted language is slower than C and C++.**
Furthermore, we considered the processors of the machines used in this project as they are highly accountable for the performance time of the codes.
We have used intel core processors i3, i5 and i7. Because of absence of Turbo boost in processor **i3, it is the slowest, whereas i7 being the fastest processor.**
Since **performance improvement is the goal** thus this study gives a trend for **future research in order to minimize the time taken for sorting.**


# References


[1] www.geeksforgeeks.com
[2] www.programiz.com
[3] www.researchgate.net
[4] www.semanticscholars.org
[5] www.cplusplus.com
[6] www.sciencedirect.com
[7] www.stackoverflow.com
[8] www.wikipedia.com
[9] www.kitchentablecomputers.com
[10] www.d.umn.edu
[11] www.whatis.techtarget.com
[12] www.tutorialsonpoint.com
[13] www.hackerearth.com
[14] www.softwaretestinghelp.com
[15] www.javapoint.com
[16] www.studytonight.com
[17] www.trustedreviews.com
[18] www.cs.stackexchange.com
[19] www.academia.edu
[20] www.educative.io
[21] www.ijlcenca.in
[22] www.sce.carleton.ca


