# Design Patterns

## Object-oriented design
OOD is based on objects to encapsulate data and behavior, it uses _sub-typing_ and _object composition_ to compose functionality into more complex ones.

## Reusing functionality

### Sub-typing & subclassing & inheritance & polymorphism & "is-a" relation
In OOD, the term `polymorphism` is commonly used to refer solely to `subtype polymorphism`, while the techniques of parametric polymorphism would be considered `generic programming`.

**White-box reuse**: With inheritance, the internals of parent classes are often visible to subclasses.

**Advantages**: Class inheritance is defined statically at compile-time.

**Disadvantages**: Any change in the parent's implementation will force the subclass to change. One cure for this is to *inherit only from abstract classes, since they usually provide little or no implementation*.

![subtype](https://upload.wikimedia.org/wikipedia/en/thumb/d/d1/Inheritance.svg/350px-Inheritance.svg.png)
Example of subtypes: where bird is the supertype and all others are subtypes as denoted by the arrow in UML notation

### Object composition & "has-a" relation
Object composition is about combining objects within compound objects.

When a composite objects

*Black-box reuse*: no internal details of objects are visible.

**Advantages**:  Fewer implementation dependencies. Favoring object composition over class inheritance helps you keep each class encapsulated and focused on one task.

![A bycicle class represented in UML, with three properties: saddle, wheels and parts, the two last having a multiplicity indicating several objects](https://upload.wikimedia.org/wikipedia/commons/thumb/4/4f/UML_properties_of_a_bicycle.png/220px-UML_properties_of_a_bicycle.png)
Object composition using UML properties to compose objects

#### Four ways of composing objects in UML:
* Property: A bicyle has a weight.
* Association/Acquaintance: A bicycle has a owner. A owner knows of a bicycle.
* Aggregation (**w/o ownership**): A bicyle has 2 wheels. The wheels may or may not outlive the bicycle.
* Composition (**w/ ownership**): A bicyle has only one frame. If the bicycle is destroyed, the frame is also destroyed.

**Another example of University -- Departments -- Professors**

![Aggregation-Composition3.png](https://upload.wikimedia.org/wikipedia/commons/d/d0/Aggregation-Composition3.png)

```cpp
class Professor;  // Defined elsewhere

class Department {
 public:
  Department(const std::string& title): title_(title) {}

 private:
  // Aggregation: |Professor|s may outlive the |Department|.
  std::vector<std::weak_ptr<Professor>> members_;
  const std::string title_;
};


class University {
 public:
  University() = default;

 private:
  // Composition: |Department|s exist only as long as the faculty exists.
  std::vector<Department> faculty_ = {
      Department("chemistry"),
      Department("physics"),
      Department("arts"),
  };
};
```

#### Delegation
Delegation enriches composition by forwarding requests or calls made to one of the class's internal components.

### Parameterized types & generics & templates
This technique defines a type without specifying all the other types it uses. The unspecified types are supplied as parameters at the point of use.

### Design for change
A design that doesn't take change into account risks major redesign in the future. Those changes might involve class redefinition and reimplementation, client modification, and retesting.

Each design pattern lets some aspect of system structure vary independently of other aspects, thereby making a system more robust to a particular kind of change.

1. Creating an object by specifying a class explicitly: Specifying a class name when you create an object could  complicate future changes. To avoid it, create objects indirectly with Abstract Factory, Factory Method, and Prototype.
2. Dependence on hardware and software platform. It's important to design your system to limit its platform dependencies with Abstract Factory, and Bridge.
3. Algorithmic dependencies. Algorithms are often extended, optimized, and replaced during development and reuse. Objects that depend on an algorithm will have to change when the algorithm changes. Therefore algorithms that are likely to change should be isolated.
4. Tight coupling. Classes that are tightly coupled are hard to reuse in isolation, since they depend on each other. Tight coupling leads to monolithic systems, where you can't change or remove a class without understanding and changing many other classes. The system becomes a dense mass that's hard to learn, port, and maintain. Loose coupling increases the probability that a class can be reused by itself and that a system can be learned, ported, modified, and extended more easily. Design patterns use techniques such as abstract coupling and layering to promote loosely coupled systems. See, Abstract Factory, Bridge, Chain of Responsibility, Command, Facade, Mediator, and Observer.