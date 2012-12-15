/* 
 * Author: Sandeep Singh
 * Date  : Nov 28, 2012
 * 
 * Copyright 2012 Sandeep Singh (sandeepsinghmails@gmail.com)
 *
 * This file is part of Fragmentation Remover.
 * Fragmentation Remover is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fragmentation Remover is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Fragmentation Remover. If not, see <http://www.gnu.org/licenses/>.
 *
 * To Compile:
 * $ gcc -o fragmentation_remover -ansi -Wall -pedantic fragmentation_remover.c
 */
#include <stdio.h>
#include <stdlib.h>
 
void fill_array (int *array);
void print_array (int *array);
void remove_fragmentation (int *array, int key);

int size;	/* Size of Array */

int main()
{
                int *p_array = NULL;
                int key;                 /* Element to be Searched & Deleted from the Array */

				printf ("\nEnter the Size of the Array: ");
				scanf  ("%d", &size);

				p_array = malloc(size*sizeof(int));
				if (NULL==p_array)
				{
					printf ("\nMemory Allocation Failed !\n");
					exit   (EXIT_FAILURE);
				}

                fill_array(p_array);

                printf ("\nOriginal Array:\n");
                print_array(p_array);

                printf ("\nEnter the Key Element: ");
                scanf  ("%d", &key);

                remove_fragmentation (p_array, key);

                printf ("\nFinal Array:\n");
                print_array(p_array);
 
                return 0;
}

void fill_array (int *array)
{
                int index;

                for (index=0; index<size; index++)
                {
                                printf ("\nEnter Array Element: ");
                                scanf  ("%d", &array[index]);
                }
}

void print_array (int *array)
{
                int index;

                for (index=0; index<size; index++)
                {
                                printf (" %d ", array[index]);
                }
                printf ("\n\n");
}

void remove_fragmentation (int *array, int key)
{
                int index;
	            int runner;
				int jumplength;
				int prev_val = -1;
				char flag = 0;

                for (index=0; index<=size-1-jumplength; index++)
                {	
					/* Non-Continuous Key Repeatitions */
					if (prev_val != array[index])
					{
						if ((array[index]==key)||(array[index+jumplength]==key))
						{
							for (runner=index+jumplength+1; runner<=size-1;runner++)
							{
								if (array[runner] != key)
								{
									jumplength += runner-(index+jumplength);
									break;
								}
							}
						}
					}
					/* Continuous Key Repeatitions */
					else	
					{
						/* Validate that I am not blindly copying the jumplength data */
						if (array[index+jumplength]==key)
						{
							/* I need to further find the jumplength */
							for (runner=index+jumplength+1; runner<=size-1;runner++)
							{
								if (array[runner] != key)
								{
									jumplength += runner-(index+jumplength);
									flag = 1;
									break;
								}
							}
							if ((runner==size) && (!flag))
							{
								/* No Key is present in the Array any further, better terminate the execution here */
								break;
							}
							else
							{
								/* Reset the Flag */
								flag = 0;
							}
						}
					}
					printf ("\nindex = %d, jumplength = %d\n", index, jumplength);
					prev_val = array[index];
					array[index] = array[index+jumplength];
				}

				if (jumplength)
				{
                	printf ("\nIgnore the Values after the Terminating Index: %d\n", index-1);
				}
				else
				{
                	printf ("\nIgnore the Values after the Terminating Index: %d\n", 0);
				}
}
