/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DynArray.cpp
 * Author: dennis
 * 
 * Created on November 16, 2017, 5:05 PM
 */
#include "DynArray.h"
#include "MP3Lib.h"


DynArray::DynArray() : m_size{0}, m_capacity{8}, m_data{new Lied[8]} {}

DynArray::DynArray(int newCapacity) : m_size{0}, m_capacity{newCapacity}, m_data{new Lied[newCapacity]} {}

DynArray::~DynArray() 
{
    delete[] m_data;
};

void DynArray::resize(int newCapacity)
{
    if(newCapacity < m_size)
    {
        Lied* new_data = new Lied[newCapacity];
        m_capacity = newCapacity;
        m_size = newCapacity;
        for(int i = 0; i < newCapacity; ++i)
        {
         new_data[i] = m_data[i];        
        }
        delete[] m_data;
        m_data = new_data;
        delete new_data;
    }
    else 
    {
     m_capacity = newCapacity;    
    }
}

Lied& DynArray::at(int index)
{
    if(index < m_size && index >= 0) return m_data[index];
}

void DynArray::push_back(Lied elem) 
{
    if(m_size == m_capacity)
    {
        resize(m_size * 2);    
    }
    m_data[m_size] = elem;
    ++m_size;
    
}

void DynArray::pop_back() 
{
    if(m_size = 0) throw;
    m_size -= 1;
}

void DynArray::erase(int index)
{
    for (int i = index; i < m_size - 1; ++i)
           m_data[i] = m_data[i+1];
    pop_back();
}

int DynArray::size() {return m_size;}
int DynArray::capacity() {return m_capacity;}

void DynArray::print()
{
    
}


