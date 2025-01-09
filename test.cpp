#include "pch.h"
//QUESTION 2
TEST(String, Constructors) {
	char s[] = "OOP-A02";

	String str0;
	ASSERT_STREQ(NULL, str0.getdata());

	String str(s);
	ASSERT_STREQ("OOP-A02", str.getdata());

	String str1(5);
	ASSERT_STREQ("", str1.getdata());

	String str2(str);
	ASSERT_STREQ(str2.getdata(), str.getdata());
	ASSERT_STRNE(str2.getdata(), str1.getdata());

}
TEST(String, squareBrackets) {

	char s[] = "Hello World!";
	String str(s);

	ASSERT_EQ('o', str[4]);
	ASSERT_EQ('\0', str[12]);

	String str1(str);
	ASSERT_EQ('H', str1[0]);
	ASSERT_EQ('!', str1[-1]);

	ASSERT_EQ('H', str1[-12]);


}
TEST(String, addition) {
	char st[] = "Assignment02";
	String str(st);
	char t1[] = "Done";
	String str1(str);
	char t3 = 'g';

	str + t1;
	ASSERT_STREQ(str.getdata(), "Assignment02Done");

	str + str1;
	ASSERT_STREQ(str.getdata(), "Assignment02DoneAssignment02");

	str + t3;
	ASSERT_STREQ(str.getdata(), "Assignment02DoneAssignment02g");

}
TEST(String, subtraction) {
	char st[] = " Fast Spring 2024 ";
	String str(st);

	str - ' ';
	ASSERT_STREQ(str.getdata(), "FastSpring2024");

	char t2[] = "20";
	str - t2;
	ASSERT_STREQ(str.getdata(), "FastSpring24");

	String str1("Spring");
	str - str1;
	ASSERT_STREQ(str.getdata(), "Fast24");

}
TEST(String, circularBrackets) {
	char st[] = "OOP-Assignment02";
	String str(st);
	ASSERT_EQ(0, str('O'));
	ASSERT_EQ(2, str('P'));
	ASSERT_EQ(5, str('s'));
	ASSERT_EQ(14, str('0'));
	ASSERT_EQ(-1, str('F'));

	char st1[] = "Spring 2024";
	char t[] = "2024";
	String test(t);
	String str1(st1);
	ASSERT_EQ(2, str1("ring"));
	ASSERT_EQ(7, str1(test));
}
TEST(String, lengthofString) {
	char st[] = " Fast Spring 2024 ";
	String str(st);

	EXPECT_EQ((int)str, 18);

	String str2(str);
	str2 + "New";

	EXPECT_EQ((int)str2, 21);

	str2 - "2024";

	EXPECT_EQ((int)str2, 17);
}
TEST(String, isEmpty) {
	char st[] = "OOP-A02";
	String str(st);
	ASSERT_EQ(false, !str);
	ASSERT_EQ(7, (int)str);

	String str1(5);
	ASSERT_EQ(true, !str1);
	ASSERT_EQ(0, (int)str1);
}
TEST(String, isEqual) {
	char st[] = "OOP-Assignment02";
	String str(st);

	char t1[] = "OOP", t2[] = "Assignment02", t3[] = "oop assignment02", t4[] = "OOP-Assignment02";
	ASSERT_EQ(false, str == t1);
	ASSERT_EQ(false, str == t2);
	ASSERT_EQ(false, str == t3);
	ASSERT_EQ(true, str == t4);

	char st1[] = "Spring 2024";
	String str1(st1);

	char t11[] = "spring 2024", t12[] = "sprIng 2022";
	ASSERT_EQ(false, str1 == t11);
	ASSERT_EQ(false, str1 == t12);
	ASSERT_EQ(true, str1 == st1);
	ASSERT_EQ(true, str1 == "Spring 2024");
}
TEST(String, equalOverloaded) {
	char st[] = "OOP-Assignment02";
	String str(st);

	str = "hello world";
	ASSERT_STREQ(str.getdata(), "hello world");
	ASSERT_EQ(11, (int)str);

	String str1("OOP-Assignment02");
	str = str1;
	ASSERT_STREQ(str.getdata(), "OOP-Assignment02");
	ASSERT_EQ(16, (int)str);

}
TEST(String, inputAndOutput) {

	char st[] = "OOP-Assignment02";
	String str(st);
	String str2;

	testing::internal::CaptureStdout();
	cout << str << str2;
	std::string output = testing::internal::GetCapturedStdout();
	std::string answer = "OOP-Assignment02\n";

	EXPECT_EQ(1, output == answer);

	cin >> str2;
	cout << str2;

}