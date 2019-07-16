// (n) {
//     new ! self =
//     n self.number =

//     (self) {
//         "MY NUMBER IS " print !
//         self.number println !
//     } self.test = 

//     self
// } Number =


// (5 Number !).test !



{
    new! self =

    (self, value) {
        value self.value =
        true self.is_something =
    } self.Just =

    (self) {
        None self.value =
        false self.is_something =
    } self.Nothing =
} Maybe