# Buffer
The buffer project series repository
# A Comparative Performance Analysis of Popular Algorithms in Languages you've studied

# Objectives 

This research based project analyses the comparison between C , C++ and Python on different sorting methods performed on different intel core processors(i3, i5 and i7) taking different inputs at a time.

# Features

- Bubble sort , Selection sort , Insertion sort , Merge sort and Radix sort algorithms are executed on C , C++ and Python.
- Execution time of the codes are calculated for different number of inputs(10000,50000,100000,500000).
- Ratios and graphs are plotted for different sets of inputs.
- Comparison on the basis of the processors (i3 , i5 and i7) is computed.

# Algorithms used

#### 1. Bubble Sort
     

#### 2. Selection Sort
       

#### 3. Insertion Sort
       

#### 4. Merge Sort
      
 
#### 5. Radix Sort
        

# Team members and their contribution

### 1.PRIYAL EKANDE
Priyal Ekande is a Second Year IT student of MKSSS Cummins College of Engineering Pune.She worked on the C language codes of different sorts ,has calculated execution time of all the programs on i5 processor and has worked on the analysis of the project.
### 2.GARGI SAMBHARE
Gargi Sambhare is a Second Year IT student of MKSSS Cummins College of Engineering Pune.She worked on the Python language codes of different sorts , has calculated execution time of all the programs on i5 processor and has worked on research methodology and abstract of the project.
### 3.MANSI SHARMA
Mansi Sharma is a Second Year ENTC student of MKSSS Cummins College of Engineering Pune.She worked on the C++ language codes of different sorts ,has calculated execution time of all the programs on i3 processor and has worked on the results and references of the project.
### 4.AKSHAT NAOGHARE
Akshat Naoghare is a Second Year COMP student of MKSSS Cummins College of Engineering Pune.She worked on calculating the ratios,plotting of performance analysis graphs , has calculated execution time of all the programs on i7 processors ,worked on literature review of the project and readme file.

# Task Accomplished by each file

#### 1. loopc.c  file
This file contains the C language code used to calculate the execution time of all the sorting techniques.
#### 2. Loopcpp.cpp  file
This file contains the C++ language code that has been used to calculate execution time of all the sorting techniques.
#### 3. looppython.py  file
This file contains the Python language code used to calculate execution time of all the sorting techniques.
#### 4.Execution time analysis.xlsx file
This file contains performance analysis ratios and graphs of C ,C++ and Python codes on different processors
#### 5.10000INPUTS.txt file
Contains 10000 inputs generated randomly.
#### 6.50000INPUTS.txt file
Contains 50000 inputs generated randomly.
#### 7.100000INPUTS.txt file
Contains 100000 inputs generated randomly.
#### 8.500000INPUTS.txt file
Contains 500000 inputs generated randomly.






# Abstract

There are many programming languages existent in this world, each of them with its own pros and cons. C, CPP, Python are very extensively used for different purposes. While C and CPP have been used since a long time and are still in demand, Python has become popular in the recent times comparatively. This **research project focuses on the comparative analysis of these languages with other different aspects like processors, sorting techniques (Sorting refers to the arrangement of data in a particular order using a particular logic.) and amount of data given as input.**
# Literature Review
- ## **_Introduction:_**

**What is an algorithm?**

An algorithm is a finite set of instructions for performing a particular task. These
instructions are nothing but statements in simple English language.
An algorithm always terminates. Some algorithms are more efficient than others, in
that less time or memory is required to execute them. The efficiency can be decided
by measuring its performance. The analysis of algorithms studies time and storage
requirements of algorithms and the way those requirements depend on the number
of items being processed.

**What is sorting?**

Sorting is nothing but systematic arrangement of data in a specific manner. It takes
lists of items as input data, perform operations on those lists and deliver sorted
arrays as output. Various sorting algorithms used in this process are:
- Bubble sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Radix Sort

**A. Bubble sort** is the simplest kind of sorting method. It is done in several
iterations, called passes. In each pass, each element will be compared to its
neighbouring element. Consecutive elements are interchanged such that element at
lower index must be smaller than the one at the higher index. The comparison
positions look like bubbles, and hence the sort is known as “bubble” sort.
&gt;ANALYSIS: The best case for bubble sort is when only one iteration is required.
The number of comparisons required is (N-1). The worst case arises when the given
array is sorted in reverse order.
Best Case = O (n)
Average Case = O (n^2)
Worst Case= O (n^2)

Read more about bubble sort here: https://www.geeksforgeeks.org/bubble-sort/

**B. Selection sort** is inefficient to be used on large lists. It scans the array to find
the smallest element and swap it with the first element. Then it again scans the array
to find the smallest element starting from the second position and swaps it with the
second element. Continuing in this fashion, we can sort the entire list. The list gets
sorted after n-1 passes.

&gt;ANALYSIS: Selecting the smallest element requires scanning all n elements, so
this takes n − 1 comparisons and then swapping or interchanging it into the first
position. Finding the next lowest element requires scanning the remaining (n − 1)
elements and so on, for
(n − 1) + (n − 2) + ... + 2 + 1 = n (n − 1) / 2= O(n2)
Best Case = O(n^2)
Average Case= O(n^2)
Worst Case= O(n^2)

Read more about selection sort here: https://www.geeksforgeeks.org/selection-sort/

**C. Insertion Sort** inserts elements at their appropriate places. Hence the name
“insertion” sort. It is less efficient than the other more advanced algorithms such as
quick sort, merge sort and heap sort. The array of values to be sorted is divided into
two sets: one that stores sorted values and one that stores unsorted values. During
each iteration, the first element in the unsorted set is picked up and inserted into the
correct position in the sorted set. It proceeds until there are elements in the unsorted
set.
&gt;ANALYSIS: The iteration starts at position 1 and moves through position (n−1), as
these are the elements that need to be inserted back into the sorted sublists. The
maximum number of comparisons for an insertion sort is (n−1) .Total numbers of
comparisons are:
(n − 1) + (n − 2) + ... + 2 + 1 = n (n − 1) / 2=O(n2)
Best Case = O(n^2)
Average Case= O(n^2)
Worst Case= O (n^2)

Read more about insertion sort here: https://www.geeksforgeeks.org/insertion-sort/

**D. Merge Sort**: uses the Divide-And-Conquer strategy. The division is carried
out dynamically. Merge sort consists of three steps:
 Divide array into two sub lists with n/2 elements each
 Conquer both the sub lists
 Combine the two into a unique sorted group.
&gt;ANALYSIS: First, the list is split into halves. We divide a list in half logn times
where n is the length of the list. The second process is the merge. So the merge
operation which results in a list of size n requires n operations. The result of this
analysis is that logn splits, each of which costs n for a total of n (log n) operations.

Best Case = O (n logn)
Average Case= O (n logn)
Worst Case= O (n logn)

Read more about merge sort here: https://www.geeksforgeeks.org/merge-sort/

**E. Radix Sort** sorts the numbers digit by digit. The number of passes depends
upon the length of the number with the most number of digits.
&gt;ANALYSIS: Since radix sort is a non-comparative algorithm, it has advantages
over comparative sorting algorithms. Here, n is the count of numbers that have to be
sorted and k is the number of digits in the largest number.
Best Case:O(n+k)
Average Case:O(nk)
Worst Case:(nk)
Read more about



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

Compiled languages are converted directly into machine language that the processor can execute. As a result, they have a tendency to be faster and more efficient to execute than interpreted languages. They also give the developer more control over hardware aspects, like memory management , CPU usage etc.

Compiled languages need a “build” step - they have to be manually compiled first. You need to “rebuild” the program whenever you would like to form a change.

Examples of pure compiled languages are Haskell, Rust, Go C, C++ and Erlang.

##  Interpreted Languages

Interpreters will run through an instruction by line and execute each command.

Interpreted languages were significantly slower than compiled languages in its earlier days. But, with the event of just-in-time compilation, that gap is shrinking.

Examples of common interpreted languages are Java, PHP, Ruby, Python, and JavaScript.
##  Advantages and Disadvantages

### Advantages of Compiled Languages

Programs compiled into native code at compile time usually tend to be faster than those translated at run time, due to the overhead of the translation process.

### Disadvantages of Compiled Languages

The most notable disadvantages are :-

* overtime needed to finish the whole compilation step before testing, and

* Platform dependence of the generated binary code.
### Advantages of Interpreted Languages

An Interpreted language gives implementations some additional flexibility over compiled implementations. Because interpreters execute the source program code themselves, the code itself is platform independent (Java’s byte code, for example). Other features include dynamic typing, and smaller executable program size.

### Disadvantages of Interpreted Languages


The most notable disadvantage is typical speed compared to compiled languages.

# Comparative Performance Analysis of Different Languages ( C , C++,Python)

## C vs C ++




The C++ vs C Comparison Ratio columns, with performance degradation ratios as high as 2.667, clearly depict the unacceptable performance of C++ versus C. This is because

C++ allows you to write down abstractions that compile-down to equivalent C. This means that with some care, a C++ program are going to be a minimum of as fast as a C one. Also C++ enables us to also build reusable abstractions with templates, OOP and functional composition .

C++ gives you the tools to encode your intentions within the type-system. This allows the compiler to get optimal binaries from your code.
## Python vs C ++




The Python vs C++ columns show performance degradation ratios as high as 404(avg).

When it involves Python vs C++, it's a dynamic language which reduces complexity when it involves collaborating and optimizes programmer efficiency. C++ has the advantage of being a statically typed language. The performance crown goes to C++ for creating a more compact and faster runtime code.

## C vs Python




Python is 662(avg) times slower than C because it is an interpreted language. python code are going to be interpreted, rather than directly by the CPU.



Python code nearly always runs during a virtual machine.



Interpreted code is usually slower than direct machine language , because it takes tons more instructions so as to implement an interpreted instruction than to implement an actual machine instruction.


# Comparative Performance Analysis of Different Processors ( i3,i5,i7)




Intel’s current core processors are divided into three ranges i.e. Core i3, Core i5 and Core i7, with several models in each range.

| **PERSONAL COMPUTER**| Clock Speed Range(Several Models) |
|--|--|
|**INTEL CORE I3**  | 3.4GHz – 4.2GHz |
|**INTEL CORE I5** | 2.4GHz – 3.8GHz |
|**INTEL CORE I7** | 2.9GHz – 4.2GHz
 |



The clock rate (or clock speed) is stated in gigahertz (GHz) and refers to the speed at which the processor can execute instructions. The faster the clock speed, the more instructions the processor can complete per second.

All else being equal, processors with faster clock speeds process data faster than those with slower clock speeds.

This may be interesting, the slowest Core i3 chips runs at a faster speed than the bottom Core i5 and Core i7.

Core i5 and Core i7s have Turbo Boost, but Core i3 processors don’t .When more power is required, Turbo Boost dynamically increases the clock speed of Core i5 and i7 processors This means that the chip can draw less power, produce less heat and only boost when it must . For example, although a Core i3-7300 runs at 4GHz compared to 3.5GHz for the Core i5-7600, the Core i5 chip can boost up to 4.1GHz when required, so will end up being quicker. A processor can only Turbo Boost for a limited amount of your time . It is a big a part of the rationale why Core i5 and Core i7 processors outperform Core i3 models in single-core-optimized tasks, albeit they need lower base clock speeds.

That’s why, i7 processor takes the least time to execute the program while i3 processor takes more time to execute than i5 as it does not have a Turbo Boost like i5 and i7.
# Result

In this research based project we have described our work on **comparative analysis of popular algorithms in C, C++ and Python.**
The algorithms that we chose, were **Bubble sort, Selection sort, Insertion sort , Merge sort and Radix sort.**
The result obtained from above analysis says that, Bubble Sort, Selection Sort and Insertion Sort are fairly straightforward, but they are relatively inefficient except for small number of inputs. Merge Sort and Radix Sort are more complicated, but also much faster for large number of inputs. Merge Sort is, on average, the fastest algorithm. Bubble Sort  algorithm is the slowest.
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


