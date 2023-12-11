#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "../Queue/TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> bf(3));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(TQueue<int> qu(-12));
}

TEST(TQueue, can_get_front)
{
    TQueue<int> qu(5);
    qu.Push(1);
    qu.Push(2);
    qu.Push(3);

    EXPECT_EQ(1, qu.Front());
}

TEST(TQueue, can_get_back)
{
    TQueue<int> qu(5);
    qu.Push(1);
    qu.Push(2);
    qu.Push(3);

    EXPECT_EQ(3, qu.Back());
}
TEST(TQueue, new_queue_is_empty)
{
    TQueue<int> qu(3);

    int sost = qu.empty();

    EXPECT_EQ(1, sost);
}

TEST(TQueue, can_push)
{
    TQueue<int> qu(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(qu.Push(a1));
    ASSERT_NO_THROW(qu.Push(a2));
    ASSERT_NO_THROW(qu.Push(a3));
    ASSERT_NO_THROW(qu.Push(a4));
    ASSERT_NO_THROW(qu.Push(a5));
}
TEST(TQueue, cat_pop)
{
    TQueue<int> qu(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(qu.Push(a1));
    ASSERT_NO_THROW(qu.Push(a2));
    ASSERT_NO_THROW(qu.Push(a3));
    ASSERT_NO_THROW(qu.Push(a4));
    ASSERT_NO_THROW(qu.Push(a5));
    int c1, c2, c3, c4, c5;
    ASSERT_NO_THROW(c1 = qu.Pop());
    ASSERT_NO_THROW(c2 = qu.Pop());
    ASSERT_NO_THROW(c3 = qu.Pop());
    ASSERT_NO_THROW(c4 = qu.Pop());
    ASSERT_NO_THROW(c5 = qu.Pop());
}
TEST(TQueue, can_push_and_pop)
{
    TQueue<int> qu(5);
    int a1 = 4;
    int a2 = 2;
    int a3 = 3;
    int a4 = 5;
    int a5 = 6;
    ASSERT_NO_THROW(qu.Push(a1));
    ASSERT_NO_THROW(qu.Push(a2));
    ASSERT_NO_THROW(qu.Push(a3));
    ASSERT_NO_THROW(qu.Push(a4));
    ASSERT_NO_THROW(qu.Push(a5));
    int c1, c2, c3, c4, c5;
    ASSERT_NO_THROW(c1 = qu.Pop());
    ASSERT_NO_THROW(c2 = qu.Pop());
    ASSERT_NO_THROW(c3 = qu.Pop());
    ASSERT_NO_THROW(c4 = qu.Pop());
    ASSERT_NO_THROW(c5 = qu.Pop());
    EXPECT_EQ(a1, c1);
    EXPECT_EQ(a2, c2);
    EXPECT_EQ(a3, c3);
    EXPECT_EQ(a4, c4);
    EXPECT_EQ(a5, c5);

}
TEST(TQueue, cant_pop_on_empty_queue)
{
    TQueue<int> qu(3);
    ASSERT_ANY_THROW(qu.Pop());
}

TEST(TQueue, cant_push_on_overflow_queue)
{
    TQueue<int> qu(3);
    qu.Push(1);
    qu.Push(1);
    qu.Push(1);
    ASSERT_ANY_THROW(qu.Push(1));
}



TEST(TQueue, return_true_for_using_Full_on_full_queue)
{
    TQueue<int> qu(3);
    qu.Push(1);
    qu.Push(2);
    qu.Push(3);
    EXPECT_EQ(qu.full(), true);
}
TEST(TQueue, return_false_for_using_Full_on_not_full_queue)
{
    TQueue<int> qu(3);
    qu.Push(1);
    qu.Push(2);
    EXPECT_EQ(qu.full(), false);
}
TEST(TQueue, return_true_for_using_Empty_on_empty_queue)
{
    TQueue<int> qu(3);
    EXPECT_EQ(qu.empty(), true);
}
TEST(TQueue, return_false_for_using_Empty_on_not_empty_queue)
{
    TQueue<int> qu(3);
    qu.Push(1);
    qu.Push(1);
    EXPECT_EQ(false, qu.empty());
}