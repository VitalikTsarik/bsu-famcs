#pragma once
#include <mpi.h>

class MPI
{
public:
	const static size_t MASTER_RANK = 0;

	MPI()
	{
		MPI_Init(nullptr, nullptr);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
	}
	~MPI()
	{
		MPI_Finalize();
	}

	void send(void* buffer, int count, MPI_Datatype datatype, int dest)
	{
		MPI_Send(buffer, count, datatype, dest, 98, MPI_COMM_WORLD);
	}

	void send_to_others(void* buffer, int count, MPI_Datatype datatype)
	{
		for (int i = 0; i < size; ++i)
			if (i != rank)
				send(buffer, count, datatype, i);
	}

	void receive(void* buffer, int count, MPI_Datatype datatype, int source)
	{
		MPI_Recv(buffer, count, datatype, source, 98, MPI_COMM_WORLD, new MPI_Status);
	}

	static auto time()
	{
		return MPI_Wtime();
	}
	
	int get_size() const
	{
		return size;
	}
	int get_rank() const
	{
		return rank;
	}

private:
	int size;
	int rank;
};
