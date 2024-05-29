using Microsoft.EntityFrameworkCore;

namespace NCCProj.Models
{
    public class DataDbContext : DbContext
    {
        public DataDbContext(DbContextOptions options) : base(options)
        {
        }
        public DbSet<users> Users { get; set; }
    }
}
