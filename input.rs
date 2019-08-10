// (n) {
//     new ! self =
//     n self.number =

//     (self) {
//         "MY NUMBER IS " print !
//         self.number println !
//         self
//     } self.test = 

//     self
// } Number =


// "Number is..." println! (((5 Number !).test !).test !).number println!

// 5 4 / println!







// () {
//     // new function returns an empty table
//     // name table `self`
//     new ! self =

//     (self, value, sign) {
//         value self.value =
//         sign self.sign =

//         self // return self at end of constructor
//     } self.constructor =


//     (self, value) {
//         value self.value =
//     } self.set_value =

//     self
// } Number =




// // cons function will call the `constructor` attribute of the value returned when calling `Number`
// (false 5 (Number !).constructor !).sign println!



// 10 n =

// () {
//     n println !
//     1 n - n =
// }

// () {
//     n
// }





// (a) {
//     (b) {
//         a
//     }
// } True =


// (a) {
//     (b) {
//         b
//     }
// } False =

// (x) {
//     (y) {
//         (z) {
//             y x z ! !
//         }
//     }
// } Pair =

// True Head =
// False Tail =


// 5 27 Pair ! ! test = 

// Head test ! println!




// fn(a) {
//     fn(b) {
//         a
//     }
// } True =

// fn(a) {
//     fn(b) {
//         b
//     }
// } False =


// 10000 a =


// while (100 a +) {
//     a println!
//     1 a - a = 
// }



// new! a =

// new! a["testing"] =
// 5 a["testing"]["whoa dude"] =


// a["testing"]["whoa dude"] println!
// a["testing"]["hey jude"] println!
// new! a["testing"]["hey jude"] =
// a["testing"]["hey jude"] println!
// 5 None =

// a println!


// new! table =

// "whoa" index =
// 5 table[index] =

// table println!

// 100000 n =
// while (n) {
//     n
//     fn (value) {
//         "WRAPPED PRINT: " print! value println!
//     } !
//     1 n - n =
// }



fn(n) {
    fn(m) {
        n m *
    }
} mul =


3 mul! triple =

5 triple!


100 x =
100 y =

while (y) {
    while (x) {
        "x: " print!
        x print!
        ", y: " print!
        y println!

        1 x - x =
    }
    1 y - y =
    100 x =
}





list! l = 


1 l push!
2 l push!
7 l push!
"exam" l push!

l println!



4 n =
while (n) {
    1 n - n =
    l[n] println!
}
