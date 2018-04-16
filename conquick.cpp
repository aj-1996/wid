
int partition(atm arr[], int low_index, int high_index)
            {
            int i, j,  key;
            atm temp;
                key = arr[low_index].get_userid();
                i= low_index + 1;
                j= high_index;
              while(1)
                {
                    while(i < high_index && key >= arr[i].get_userid())
                        i++;
                    while(key < arr[j].get_userid())
                        j--;
                    if(i < j)
                        {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        }
                    else
                        {
                            temp= arr[low_index];
                            arr[low_index] = arr[j];
                            arr[j]= temp;
                            return(j);
                        }
                }
            };

void quicksort_om(atm arr[], int low_index, int high_index)
        {
            int j;

            if(low_index < high_index)
                {
                j = partition(arr, low_index, high_index);
                cout<<"Pivot element with index "<<j<<" has been found out by thread "<<k<<"\n";

                #pragma omp parallel sections
                    {
                        #pragma omp section
                        {
                            k=k+1;
                            quicksort_om(arr, low_index, j - 1);
                        }//end of section

                        #pragma omp section
                        {
                            k=k+1;
                            quicksort_om(arr, j + 1, high_index);
                        }//end of section

                    }// end of #pragma OMP parallel sections
                }
        };


