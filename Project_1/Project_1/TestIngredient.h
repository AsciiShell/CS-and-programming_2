#pragma once
#include "Ingredient.h"
#include <assert.h>
void testConstructorDefault()
{
	Ingredient ingredient;
	assert(ingredient.getName().isEmpty());
	assert(ingredient.getMeasure() == Ingredient::GRAM);
	assert(ingredient.getCount() == 0);
}

void testConstructorInit()
{
	Ingredient ingredient("�����", Ingredient::PIECE, 10);
	assert(ingredient.getName() == "�����");
	assert(ingredient.getMeasure() == Ingredient::PIECE);
	assert(ingredient.getCount() == 10);
}

void testConstructorInitCountWrong()
{
	Ingredient ingredient("�����", Ingredient::PIECE, -10);
	assert(ingredient.getCount() == 0);
}

void testConstructorCopy()
{
	Ingredient ingredient1("�����", Ingredient::PIECE, 10);
	Ingredient ingredient2(ingredient1);
	assert(ingredient1.getName() == ingredient2.getName());
	assert(ingredient1.getMeasure() == ingredient2.getMeasure());
	assert(ingredient1.getCount() == ingredient2.getCount());
}

void testSetName()
{
	Ingredient ingredient;
	ingredient.setName("����");
	assert(ingredient.getName() == "����");
}

void testSetNameWrong()
{
	Ingredient ingredient("�����", Ingredient::PIECE, 10);
	ingredient.setName("");
	assert(!ingredient.getName().isEmpty());
}

void testSetMeasure()
{
	Ingredient ingredient;
	ingredient.setMeasure(Ingredient::MILLILITER);
	assert(ingredient.getMeasure() == Ingredient::MILLILITER);
}

void testSetCount()
{
	Ingredient ingredient;
	ingredient.setCount(127);
	assert(ingredient.getCount() == 127);
}

void testSetCountWrong()
{
	Ingredient ingredient;
	ingredient.setCount(-127);
	assert(ingredient.getCount() != -127);
}

void runTestsIngredient()
{
	testConstructorDefault();

	testConstructorInit();
	testConstructorInitCountWrong();

	testConstructorCopy();

	testSetName();
	testSetNameWrong();
	testSetMeasure();
	testSetCount();
	testSetCountWrong();
}
