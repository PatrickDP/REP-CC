const swap = (array, i, j) => {
    let aux = 0
    
    aux = array[j]
    array[j] = array[i]
    array[i] = aux

    return array
}

const simpleBubbleSort = list => {
    let aux = 0

    for(let i = 0; i < list.length; i++) {
        for(let j = 0; j < list.length - 1; j++) {
            if(list[j] > list[j + 1]) {
                swap(list, j, (j + 1))
            }
        }
    }

    return `Bubble Sorted list: ${list}`
}

otmBubbleSort = list => {
    let aux = list.length - 1
    let isChange = true
    let lastModif = list.length

    while(isChange) {
        isChange = false

        for(let j = 0; j < lastModif - 1; j++) {
            if(list[j] > list[j + 1]) {
                isChange = true
                aux = j
                swap(list, j, (j + 1))
            }
        }
        lastModif = aux + 1
    }

    return `Otimized Bubble Sorted list: ${list}`
}

const insertionSort = list => {
    let j = 0
    let value = 0
    
    for(let i = 1; i < list.length; i++) {
        j = i - 1
        value = list[i]

        while((j >= 0) && (value < list[j])) {
            list[j + 1] = list[j]
            j--
        }
        list[j + 1] = value
    }

    return `Insertion Sorted list: ${list}`
}

const selectionSort = list => {
    min = 0

    for(let i = 0; i < list.length - 1; i++) {
        min = i

        for(let j = i + 1; j <= list.length - 1; j++) {
            if(list[j] < list[min]) {
                min = j
            }
        }
        swap(list, i, min)
    }

    return `Selection Sorted list: ${list}`
}

const quickSort = (list, left_element, right_element) => {
    if(left_element < right_element) {
        const partition = (list, left_element, right_element) => {
            pivot_element = list[right_element]
            center_element = left_element

            for(let i = left_element; i < right_element; i++) {
                if(list[i] < pivot_element) {
                    swap(list, center_element, i)
                    center_element++
                }
            }
            swap(list, center_element, right_element)

            return center_element
        }

        center_element = partition(list, left_element, right_element)
        
        quickSort(list, left_element, center_element - 1)
        quickSort(list, center_element + 1, right_element)
    }

    return `Quick sorted list: ${list}`
}

const  mergeSort = (list, auxiliar_list, left_limit, right_limit, isRecursive) => {
    if(left_limit < right_limit - 1) {
        const merge = (list, auxiliar_list,  left_limit, mid_element, right_limit) => {
            let left_limit_aux = left_limit
            let mid_element_aux = mid_element

            // console.log(`(Merge) left_limit_aux = ${left_limit_aux} - mid_element_aux = ${mid_element_aux}`)

            for(let i = left_limit_aux; i < right_limit; i++) {
                if(left_limit_aux < mid_element && ((mid_element_aux >= right_limit) || (list[left_limit_aux] < list[mid_element_aux]))) {
                    auxiliar_list[i] = list[left_limit_aux]
                    left_limit_aux++
                } else {
                    auxiliar_list[i] = list[mid_element_aux]
                    mid_element_aux++
                }
            }
        }
        
        let mid_element = parseInt((left_limit + right_limit) / 2)

        // console.log(`(${isRecursive}) left_limit = ${left_limit} - mid_element = ${mid_element} - right limit = ${right_limit}`)

        mergeSort(auxiliar_list, list, left_limit, mid_element, 'Left recursion')
        mergeSort(auxiliar_list, list, mid_element, right_limit, 'Right Recursion')
        merge(auxiliar_list, list, left_limit, mid_element, right_limit)
    }

    return `(Merge sorted list): ${list}`
}

list  = [5, 3, 2, 1, 4, 7, 6, 9, 8, 0]
list2 = [0, 7, 3, 9, 6,	4, 8, 1, 5, 2]
list3 = [1, 5, 0, 9, 3, 8, 6, 2, 4, 7]
list4 = [5, 9, 2, 8, 4, 0, 7, 6, 1, 3]
list5 = [6, 0, 5, 7, 4, 3, 9, 8, 1, 2]
list6 = [9, 8, 1, 5, 0, 4, 6, 2, 7, 3]

// Copia os elementos de um array sem usar referência
auxiliar_list = list6.slice()

console.log(`Size of list: ${list.length}`)

console.log(simpleBubbleSort(list))
console.log(otmBubbleSort(list2))
console.log(insertionSort(list3))
console.log(selectionSort(list4))
console.log(quickSort(list5, 0, list5.length - 1))
console.log(mergeSort(list6, auxiliar_list, 0, list6.length, "Initial call function"))